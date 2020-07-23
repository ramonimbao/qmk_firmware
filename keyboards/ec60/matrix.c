#include <quantum.h>
#include "ec60.h"
#include "analog.h"
#include "matrix.h"
#include "print.h"

static const pin_t row_pins[] = MATRIX_ROW_PINS;
static const pin_t col_pins[] = MATRIX_COL_PINS;
static const pin_t read_pins[] = COLUMN_READ_PINS;
static const uint8_t column_order[] = COLUMN_ORDER;

uint16_t release_points[MATRIX_ROWS][MATRIX_COLS] = RELEASE_POINTS;
uint16_t actuation_points[MATRIX_ROWS][MATRIX_COLS] = ACTUATION_POINTS;

static matrix_row_t last_matrix[MATRIX_ROWS];

void matrix_init_custom(void) {
    // INITIALIZE HARDWARE

    // Set ADC reference
    analogReference(ADC_REF_INTERNAL);

    // Set row pins to high Z (Maybe I should be setting this to LOW instead of HIGH Z?)
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        // setPinInput(row_pins[row]);
        setPinOutput(row_pins[row]);
        writePinLow(row_pins[row]);
    }
    // Disable output on multiplexers (Mux is OE Active LOW)
    setPinOutput(OUTPUT_ENABLE_PIN);
    writePinHigh(OUTPUT_ENABLE_PIN);

    // Set multiplexer selection pins to low
    for (uint8_t i = 0; i < 6; i++) {
        setPinOutput(col_pins[i]);
        writePinLow(col_pins[i]);
    }

    // Set analog read pins high Z
    for (uint8_t i = 0; i < 2; i++) {
        setPinInputHigh(read_pins[i]);
    }

    // Set drain pin to high Z
    setPinInput(DRAIN_PIN);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        // Store last data
        last_matrix[row] = current_matrix[row];

        // for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        for (uint8_t col = 0; col < 9; col++) {
            wait_us(5);

            // Set row 0 to HIGH
            writePinHigh(row_pins[row]);

            // Float drain pin
            setPinInput(DRAIN_PIN);

            // Disable interrupts
            cli();

            // Select the right multiplexer line
            uint8_t is_upper = (col & 0b1000) >> 3;  // Whether to select the lower or upper multiplexer
            if (col == 9) {
                uprintf("is_upper: %u\n", is_upper);
            }
            uint8_t sel0     = col & 0b0001;
            uint8_t sel1     = col & 0b0010;
            uint8_t sel2     = col & 0b0100;
            if (is_upper) {
                sel0 ? writePinHigh(col_pins[3]) : writePinLow(col_pins[3]);
                sel1 ? writePinHigh(col_pins[4]) : writePinLow(col_pins[4]);
                sel2 ? writePinHigh(col_pins[5]) : writePinLow(col_pins[5]);
            } else {
                sel0 ? writePinHigh(col_pins[0]) : writePinLow(col_pins[0]);
                sel1 ? writePinHigh(col_pins[1]) : writePinLow(col_pins[1]);
                sel2 ? writePinHigh(col_pins[2]) : writePinLow(col_pins[2]);
            }

            // Enable output on mux
            writePinLow(OUTPUT_ENABLE_PIN);

            int16_t value = analogReadPin(read_pins[is_upper]);
            // uprintf("Value: %u\n", value);

            // Wait a bit, then set row to LOW
            writePinLow(row_pins[row]);

            // Enable interrupts
            sei();

            // Disable output on mux and set columns to low
            writePinHigh(OUTPUT_ENABLE_PIN);
            for (uint8_t i = 0; i < 6; i++) {
                setPinOutput(col_pins[i]);
                writePinLow(col_pins[i]);
            }

            // Ground drain pin
            setPinOutput(DRAIN_PIN);
            writePinLow(DRAIN_PIN);

            // Process the ADC reading
            // uint8_t current_col = last_matrix[row] >> column_order[col];
            // There has to be a better way to do handle buttons with different sensitivities than
            // with if-else statements.
            //
            // I was hoping to do a matrix of release and actutation points (see config.h) but for some reason
            // it's not working. Even if I set the actuation point to something high so it SHOULDN'T actuate, it
            // still does. Maybe I'm doing it wrong with the arrays or something. TODO: Revisit
            // if (row == 2 && col == 0)  {
            //     if (value <= 85 /*release_points[row][column_order[col]]*/) {
            //         if (current_col) {
            //             // If actuated and goes below release point, consider as released
            //             current_matrix[row] &= ~(MATRIX_ROW_SHIFTER << column_order[col]);
            //         }
            //     } else if (value >= 105 /*actuation_points[row][column_order[col]]*/) {
            //         if (!current_col) {
            //             // If not actuated and goes above actuation point, consider as pressed
            //             current_matrix[row] |= (MATRIX_ROW_SHIFTER << column_order[col]);
            //         }
            //     }
            // } else {
                if (value <= /*70*/ release_points[row][column_order[col]]) {
                    // if (current_col) {
                        // If actuated and goes below release point, consider as released
                        current_matrix[row] &= ~(MATRIX_ROW_SHIFTER << column_order[col]);
                    // }
                } else if (value >= /*85*/ actuation_points[row][column_order[col]]) {
                    // if (!current_col) {
                        // If not actuated and goes above actuation point, consider as pressed
                        current_matrix[row] |= (MATRIX_ROW_SHIFTER << column_order[col]);
                    // }
                }
            // }
            // writePinHigh(OUTPUT_ENABLE_PIN);
        }
    }

    // Check if the matrix has changed
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        if (last_matrix[row] != current_matrix[row]) {
            changed = true;
        }
    }

    /*
    // MATRIX SCANNING ROUTING
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        // Store last data
        last_matrix[row] = current_matrix[row];

        // Clear data
        current_matrix[row] = 0;

        // Go through columns
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t is_upper = (col & 0b1000) >> 3; // Whether to select the lower or upper multiplexer
            uint8_t sel0 = col & 0b0001;
            uint8_t sel1 = col & 0b0010;
            uint8_t sel2 = col & 0b0100;
            uint8_t offset = 0;
            if (is_upper) {
                offset = 3; // Offset index by 3 if using the upper multiplexer
            }
            sel0 ? writePinHigh(col_pins[0 + offset]) : writePinLow(col_pins[0 + offset]);
            sel1 ? writePinHigh(col_pins[1 + offset]) : writePinLow(col_pins[1 + offset]);
            sel2 ? writePinHigh(col_pins[2 + offset]) : writePinLow(col_pins[2 + offset]);

            // Enable output on multiplexers (Mux is Active LOW)
            writePinLow(OUTPUT_ENABLE_PIN);

            // Ensure drain pin is high Z before reading ADC
            setPinInput(DRAIN_PIN);

            // Set row to high
            setPinOutput(row_pins[row]);
            writePinHigh(row_pins[row]);

            // Read the ADC
            uint16_t key_value = (analogReadPin(read_pins[is_upper]));

            // Wait a bit for the ADC to read the value, then set the drain pin to output and LOW.
            wait_us(5);
            setPinOutput(DRAIN_PIN);
            writePinLow(DRAIN_PIN);

            // uprintf("Row: %u | Col: %u | Key Value: %u\n", row, col, key_value);

            // Disable output on multiplexers (Mux is Active LOW)
            writePinHigh(OUTPUT_ENABLE_PIN);

            // Process the ADC reading
            uint8_t current_col = current_matrix[row] >> column_order[col];
            if (key_value <= release_point) {
                if (current_col) {
                    // If actuated and goes below release point, consider as released
                    current_matrix[row] &= ~(MATRIX_ROW_SHIFTER << column_order[col]);
                }
            }
            else if (key_value >= actuation_point) {
                if (!current_col) {
                    // If not actuated and goes above actuation point, consider as pressed
                    current_matrix[row] |= (MATRIX_ROW_SHIFTER << column_order[col]);
                }
            } // Not sure if I should be handling the in between the release point and actuation point yet

            // Set row to LOW
            writePinLow(row_pins[row]);
        }
    }

    // Check if the matrix has changed
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        if (last_matrix[row] != current_matrix[row]) {
            changed = true;
        }
    }
    */

    return changed;
}

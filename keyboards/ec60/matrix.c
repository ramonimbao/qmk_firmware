#include <quantum.h>
#include "analog.h"
#include "matrix.h"

static const pin_t row_pins[] = MATRIX_ROW_PINS;
static const pin_t col_pins[] = MATRIX_COL_PINS;
static const pin_t read_pins[] = COLUMN_READ_PINS;
static const uint8_t column_order[] = COLUMN_ORDER;

static matrix_row_t last_matrix[MATRIX_ROWS];

// ADC reading level points
static const uint16_t actuation_point = 700; // These values are currently arbitrary
static const uint16_t release_point = 350;

void matrix_init_custom(void) {
    // INITIALIZE HARDWARE
    // Set row pins to high Z
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        setPinInputHigh(row_pins[row]);
    }
    // Disable output on multiplexers
    setPinOutput(OUTPUT_ENABLE_PIN);
    writePinLow(OUTPUT_ENABLE_PIN);

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
    setPinInputHigh(DRAIN_PIN);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    // MATRIX SCANNING ROUTING
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        // Store last data
        last_matrix[row] = current_matrix[row];

        // Clear data
        current_matrix[row] = 0;

        // Set row to high
        setPinOutput(row_pins[row]);
        writePinHigh(row_pins[row]);

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

            // Enable output on multiplexers
            writePinHigh(OUTPUT_ENABLE_PIN);

            // Read the ADC
            uint16_t key_value = (analogReadPin(read_pins[is_upper]));

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
                    current_matrix[row] |= MATRIX_ROW_SHIFTER << column_order[col];
                }
            } // Not sure if I should be handling the in between the release point and actuation point yet
        }

        // Set row to high Z
        setPinInputHigh(row_pins[row]);
    }

    return changed;
}

# Wete, Wete R2, Wete EC

Southpaw numpad 75% boards.

* Keyboard Maintainer: [Ramon Imbao](https://github.com/ramonimbao)
* Hardware Supported:
    - STM32F072 (R1),
    - ATmega32u4 (R2),
    - STM32F072 (EC)

Make example for these keyboards (after setting up your build environment):

    make rmi_kb/wete/v1:default
    
    make rmi_kb/wete/v2:default
    
    make rmi_kb/wete/ec:default
    
Flashing example for these keyboards:

    make rmi_kb/wete/v1:default:flash
    
    make rmi_kb/wete/v2:default:flash
    
    make rmi_kb/wete/ec:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).


## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard (R1, R2)
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead (R2)
    - Short the `BOOT` pads with tweezers (R1, EC) before pressing reset
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available (R1, R2, EC)

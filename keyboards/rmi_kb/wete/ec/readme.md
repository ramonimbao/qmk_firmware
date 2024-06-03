# Wete EC

![Wete EC PCB](https://i.imgur.com/THSrR13l.png)

A southpaw full-sized keyboard.

* Keyboard Maintainer: [Ramon Imbao](https://github.com/ramonimbao)
* Hardware Supported: STM32F072CBT6

Make example for this keyboard (after setting up your build environment):

    make rmi_kb/wete/ec:default
    
Flashing example for this keyboard:

    make rmi_kb/wete/ec:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader:

1) Short the `BOOT` pads with tweezers
2) Press the reset button

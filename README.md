# STM32F103C8T6 Standard Library Project
## 基于江科视频的STM32标准库工程模板

This is a template project for STM32F103C8T6 microcontroller using the Standard Peripheral Library, based on Jiangke (江科) video tutorials.

## Project Structure

```
├── Libraries/
│   ├── CMSIS/
│   │   └── CM3/
│   │       ├── CoreSupport/          # CMSIS Core files
│   │       └── DeviceSupport/
│   │           └── ST/
│   │               └── STM32F10x/
│   │                   ├── startup/  # Startup files
│   │                   ├── stm32f10x.h
│   │                   ├── system_stm32f10x.h
│   │                   └── system_stm32f10x.c
│   └── STM32F10x_StdPeriph_Driver/
│       ├── inc/                      # Standard Peripheral Library headers
│       └── src/                      # Standard Peripheral Library source
├── User/
│   ├── main.c                        # Main application
│   └── stm32f10x_conf.h             # Library configuration
├── Output/                           # Build output directory
├── Makefile                          # Build configuration
└── STM32F103C8Tx_FLASH.ld           # Linker script
```

## Hardware Requirements

- STM32F103C8T6 Development Board (Blue Pill)
- ST-Link V2 or compatible programmer
- USB to Serial adapter (optional, for debugging)

## Software Requirements

- ARM GCC Toolchain (arm-none-eabi-gcc)
- Make
- OpenOCD or ST-Link Utility (for flashing)

## Building the Project

To build the project, run:

```bash
make
```

This will generate the following files in the `Output` directory:
- `STM32F103C8T6_Template.elf` - ELF executable
- `STM32F103C8T6_Template.hex` - Intel HEX file
- `STM32F103C8T6_Template.bin` - Binary file

To clean the build:

```bash
make clean
```

## Flashing the Firmware

### Using OpenOCD

```bash
openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg -c "program Output/STM32F103C8T6_Template.elf verify reset exit"
```

### Using ST-Link Utility

1. Open ST-Link Utility
2. Connect to the target
3. Load the `.hex` or `.bin` file
4. Program the flash

## Example Application

The default `main.c` includes a simple LED blink example:
- LED on PC13 (onboard LED on Blue Pill boards)
- Blinks at approximately 1Hz

## Features

- ✅ CMSIS Core support for Cortex-M3
- ✅ STM32F10x Standard Peripheral Library
- ✅ GPIO driver implementation
- ✅ RCC (Reset and Clock Control) driver
- ✅ System initialization
- ✅ Makefile for easy compilation
- ✅ Linker script for STM32F103C8T6

## License

This project template is based on STMicroelectronics Standard Peripheral Library and follows the respective licenses.

## References

- STM32F103C8T6 Datasheet
- STM32F10x Standard Peripheral Library Documentation
- Jiangke (江科) STM32 Video Tutorials

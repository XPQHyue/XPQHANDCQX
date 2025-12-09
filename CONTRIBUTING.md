# Contributing to STM32F103C8T6 Standard Library Project

## Project Overview

This project provides a template for STM32F103C8T6 microcontroller development using the Standard Peripheral Library, based on Jiangke (江科) video tutorials.

## Development Setup

### Prerequisites

1. **ARM GCC Toolchain**
   ```bash
   # Ubuntu/Debian
   sudo apt-get install gcc-arm-none-eabi
   
   # macOS (Homebrew)
   brew install arm-none-eabi-gcc
   ```

2. **Build Tools**
   ```bash
   sudo apt-get install make
   ```

3. **Flash Tools** (choose one)
   - OpenOCD
   - ST-Link Utility
   - stm32flash

### Building the Project

```bash
# Clean previous builds
make clean

# Build the project
make

# Output files will be in the Output/ directory
```

## Code Structure

### Directory Layout

- **Libraries/CMSIS/**: CMSIS (Cortex Microcontroller Software Interface Standard) files
  - Core support and device-specific headers
  - System initialization code
  - Startup assembly files

- **Libraries/STM32F10x_StdPeriph_Driver/**: Standard Peripheral Library
  - Header files in `inc/`
  - Source files in `src/`
  - Peripheral drivers (GPIO, RCC, etc.)

- **User/**: Application code
  - `main.c`: Main application entry point
  - `stm32f10x_conf.h`: Library configuration

## Adding New Features

### Adding a New Peripheral Driver

1. Add the header file to `Libraries/STM32F10x_StdPeriph_Driver/inc/`
2. Add the source file to `Libraries/STM32F10x_StdPeriph_Driver/src/`
3. Include the header in `User/stm32f10x_conf.h`
4. Update the Makefile to include the new source file

Example:
```makefile
C_SOURCES =  \
User/main.c \
Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c \
Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c \
Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c \
Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_uart.c  # New driver
```

### Coding Standards

1. **Naming Conventions**
   - Functions: `PeripheralName_FunctionDescription()` (e.g., `GPIO_Init()`)
   - Variables: Descriptive camelCase or snake_case
   - Macros: UPPERCASE_WITH_UNDERSCORES

2. **Comments**
   - Use Doxygen-style comments for functions
   - Include brief descriptions for complex code blocks
   - Document register manipulations

3. **Error Handling**
   - Use assert_param() for parameter validation when USE_FULL_ASSERT is defined
   - Check return values from functions

## Testing

### Hardware Testing

1. Connect ST-Link to your STM32F103C8T6 board
2. Flash the firmware
3. Verify the LED blinks on PC13

### Debugging

Use GDB with OpenOCD:
```bash
# Terminal 1: Start OpenOCD
openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg

# Terminal 2: Start GDB
arm-none-eabi-gdb Output/STM32F103C8T6_Template.elf
(gdb) target remote localhost:3333
(gdb) load
(gdb) monitor reset halt
(gdb) continue
```

## Common Issues

### Build Errors

**Issue**: `arm-none-eabi-gcc: command not found`
- **Solution**: Install the ARM GCC toolchain

**Issue**: Linker errors about missing symbols
- **Solution**: Check that all required source files are listed in the Makefile

### Flash Errors

**Issue**: Cannot connect to target
- **Solution**: Check ST-Link connection and power to the board

**Issue**: Flash verification failed
- **Solution**: Try erasing the chip first or check for write protection

## License

This project uses STMicroelectronics Standard Peripheral Library which is subject to the applicable licenses. See LICENSE file for details.

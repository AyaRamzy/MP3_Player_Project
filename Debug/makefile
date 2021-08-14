################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
MP3_player.lss \

FLASH_IMAGE += \
MP3_player.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: MP3_player.elf secondary-outputs

# Tool invocations
MP3_player.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MP3_player.map -mmcu=atmega32 -o "MP3_player.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MP3_player.lss: MP3_player.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MP3_player.elf  >"MP3_player.lss"
	@echo 'Finished building: $@'
	@echo ' '

MP3_player.hex: MP3_player.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MP3_player.elf  "MP3_player.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MP3_player.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MP3_player.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: MP3_player.elf
	@echo 'Invoking: AVRDude'
	C:\Users\Aya Ramzy\Desktop\IMT Tools\SDK\IMT_SDK_Win_32\WinAVR\bin\avrdude -pm32 -cusbasp -Uflash:w:MP3_player.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MP3_player.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets


C_SRC = 

CXX_SRC = main.cpp

ASM_SRC =

DEFINES =

INCLUDEDIRS = -iquote . -I common/stm_include -I common/cmsis_include

PROJECT = minblink

LD_SCRIPT = linkerscript.ld

TARGET = arm-none-eabi-

OUT=out

CC = $(TARGET)gcc
CXX = $(TARGET)g++
AS = $(TARGET)gcc -x assembler-with-cpp
OBJCOPY = $(TARGET)objcopy

CPUFLAGS = -mcpu=cortex-m3 -mthumb
COMMONFLAGS = $(CPUFLAGS) -MD -MP -MF $(@:.o=.d) $(DEFINES)

CFLAGS = $(COMMONFLAGS) -O2 \
         -std=gnu99 $(INCLUDEDIRS)

CXXFLAGS = $(COMMONFLAGS) -O2 \
         -fno-rtti -fno-exceptions \
         -std=gnu++14 $(INCLUDEDIRS)

ASFLAGS = $(COMMONFLAGS) $(INCLUDEDIRS)

LDFLAGS = $(CPUFLAGS) -T$(LD_SCRIPT) -nostartfiles

OBJ_FILES = $(addprefix $(OUT)/, $(notdir $(ASM_SRC:.S=.o)))  \
            $(addprefix $(OUT)/, $(notdir $(C_SRC:.c=.o)))    \
            $(addprefix $(OUT)/, $(notdir $(CXX_SRC:.cpp=.o)))
DEPS = $(OBJ_FILES:.o=.d)

# unconditionally ensure output directory
$(shell test -d $(OUT) || mkdir $(OUT))

all: $(OUT)/$(PROJECT).bin

clean:
	rm -f $(OUT)/*

$(OUT)/%.o: %.c Makefile
	@echo CC $<
	@$(CC) -c $(CFLAGS) $< -o $@

$(OUT)/%.o: %.cpp Makefile
	@echo CXX $<
	@$(CXX) -c $(CXXFLAGS) $< -o $@

$(OUT)/%.o: %.S Makefile
	$(AS) -c $(ASFLAGS) $< -o $@


$(OUT)/$(PROJECT).elf: $(OBJ_FILES) Makefile $(LD_SCRIPT)
	$(CXX) $(LDFLAGS) $(OBJ_FILES) -o $@

$(OUT)/$(PROJECT).bin: $(OUT)/$(PROJECT).elf Makefile
	$(OBJCOPY) -O binary $< $@


-include $(DEPS)

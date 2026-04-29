# Makefile for PJ64 DirectInput Plugin
# Alternative build system if Visual Studio isn't available

CC = gcc
WINDRES = windres
DLLTOOL = dlltool

CFLAGS = -Wall -Wextra -O2 -DWIN32 -D_WINDOWS -I.
LDFLAGS = -shared -Wl,--out-implib,libpj64_dinput.a -Wl,--export-all-symbols

# Source files
SOURCES = main.c dinput_backend.c bindings.c bind_capture.c calibration.c
OBJECTS = $(SOURCES:.c=.o)
RESOURCE_OBJ = pj64_dinput.o

# Libraries
LIBS = -ldinput8 -ldxguid -luser32 -lcomctl32 -lkernel32

# Targets
all: PJ64_DInput.dll

PJ64_DInput.dll: $(OBJECTS) $(RESOURCE_OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

pj64_dinput.o: pj64_dinput.rc resource.h
	$(WINDRES) $< -o $@

clean:
	rm -f $(OBJECTS) $(RESOURCE_OBJ) PJ64_DInput.dll libpj64_dinput.a

.PHONY: all clean


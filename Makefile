CC=gcc

ifeq ($(OS),Windows_NT)
RM = del /Q /F
CP = copy /Y
ifdef ComSpec
SHELL := $(ComSpec)
endif
ifdef COMSPEC
SHELL := $(COMSPEC)
endif
else
RM = rm -rf
CP = cp -f
endif

CFLAGS=-g -Wall


default: ted

ted: ted.c
	$(CC) -o ted ted.c $(CFLAGS)


.PHONY: clean
clean:
	-$(RM) ted
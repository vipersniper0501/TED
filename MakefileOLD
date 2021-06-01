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


WARNINGS=-g -Wall -Wformat-security -Wstrict-overflow -Wsign-compare \
		-Wempty-body -Wignored-qualifiers -Wuninitialized -Wtype-limits -Woverride-init \
		-Wno-multichar -Wno-attributes -Wnull-dereference

default: ted

ted: src/ted.c
	$(CC) -o ted src/ted.c $(WARNINGS)


.PHONY: clean
clean:
	-$(RM) ted

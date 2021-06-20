#ifndef FILETYPES_HEADER_FILE
#define FILETYPES_HEADER_FILE

#include "data.h"

#define HLDB_ENTRIES (sizeof(HLDB) / sizeof(HLDB[0]))

char *C_HL_extensions[4];
char *C_HL_keywords[24];

struct editorSyntax HLDB[1];

#endif

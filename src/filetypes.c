#include "filetypes.h"
#include "defines.h"

char *C_HL_extensions[4] = { ".c", ".h", ".cpp", NULL };
char *C_HL_keywords[24] = {
    "switch", "if", "while",
    "for", "break", "continue",
    "return", "else", "struct",
    "union", "typedef", "static",
    "enum", "class", "case",
    "int|", "long|", "double|",
    "float|", "char|", "unsigned|",
    "signed|", "void|", NULL
};

struct editorSyntax HLDB[1] = {
    {
        "c",
        C_HL_extensions,
        C_HL_keywords,
        "//", "/*", "*/",
        HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS
    },
};


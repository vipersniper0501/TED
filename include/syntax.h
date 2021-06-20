#ifndef SYNTAX_HEADER_FILE
#define SYNTAX_HEADER_FILE

#include "data.h"

int is_seperator(int c);
void editorUpdateSyntax(erow *row);
int editorSyntaxToColor(int hl);
void editorSelectSyntaxHighlight();

#endif

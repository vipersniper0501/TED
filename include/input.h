#ifndef INPUT_HEADER_FILE
#define INPUT_HEADER_FILE

char *editorPrompt(char *prompt, void (*callback)(char *, int));
void editorMoveCursor(int key);
void editorProcessKeypress();

#endif

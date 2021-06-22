/*
 * This is the starting src file for the TED text editor.
 */

#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "syntax.h"
#include "fileio.h"
#include "terminal.h"
#include "input.h"
#include "output.h"
#include "defines.h"


int cliParser(char *a, int dashlen)
{
    memmove(a, a+dashlen, strlen(a));

    if (strlen(a) == 0) {
        printf("Please enter a command...\n"
                "Do: `ted --help` or `ted -h` for a list of available commands\n");
        return 0;
    }

    if (strcmp(a, "help") == 0 || strcmp(a, "h") == 0){
        printf("Use: ted [file]\n"
                "\n"
                "Options:\n"
                "--version (-v)        Print TED Version\n");
        return 0;
    }

    if (strcmp(a, "version") == 0 || strcmp(a, "v") == 0) {
        printf("TED Version: %s\n", TED_VERSION);
        return 0;
    }

    return 0;
}

/*
 * Set up the editor by reseting all of the editor settings
 */
void initEditor()
{
    E.cx = 0;
    E.cy = 0;
    E.rx = 0;
    E.rowoff = 0;
    E.coloff = 0;
    E.numrows = 0;
    E.row = NULL;
    E.dirty = 0;
    E.filename = NULL;
    E.statusmsg[0] = '\0';
    E.statusmsg_time = 0;
    E.syntax = NULL;

    if (getWindowSize(&E.screenrows, &E.screencols) == -1) die("getWindowSize");
    E.screenrows -= 2;
}

int main(int argc, char *argv[]) {
    enableRawMode();
    initEditor();
    if (argc >= 2)
    {
        if (strncmp(argv[1], "--", strlen("--")) == 0) {
            disableRawMode();
            cliParser(argv[1], 2);
            exit(0);
        } else if (strncmp(argv[1], "-", strlen("-")) == 0) {
            disableRawMode();
            cliParser(argv[1], 1);
            exit(0);
        }
    } else {
        editorOpen(argv[1]);
    }

    editorSetStatusMessage("HELP: Ctrl-S = save | Ctrl-Q = quit | Ctrl-F = find");

    // This while loop is the main "game loop" from where the editor runs
    while (1)
    {
        editorRefreshScreen();
        editorProcessKeypress();
    }
    return 0;
}

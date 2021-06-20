#ifndef APPENDBUF_HEADER_FILE
#define APPENDBUF_HEADER_FILE

struct abuf
{
    char *b;
    int len;
};

/*
 * ABUF_INIT represents an empty buffer
 */
#define ABUF_INIT {NULL, 0}

void abAppend(struct abuf *ab, const char *s, int len);
void abFree(struct abuf *ab);

#endif

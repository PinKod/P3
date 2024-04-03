#include "../Headers/data_io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *input() {
    char tc = ' ';
    // scanf("%c", &tc);
    char *str = NULL;
    int i = -1;
    while (1) {
        scanf("%c", &tc);
        if (tc == '\n' || tc == '\0') {
            break;
        }
        str = scale_string(str);
        i += 1;
        str[i] = tc;
    }
    return str;
}

char *scale_string(char *str) {
    if (str != NULL) {
        size_t len = strlen(str) + 1;
        str = realloc(str, sizeof(char) * len);
    } else {
        str = (char *)malloc(sizeof(char));
    }
    return str;
}

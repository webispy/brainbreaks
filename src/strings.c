#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings.h"
#include "util.h"

char *reverseString(char* s)
{
    int i = 0, len = 0;
    char buf;

    if (!s)
        return NULL;

    if (s[0] == '\0')
        return s;

    while(s[len] != '\0')
        len++;
    len--;

    while(i < len) {
        buf = s[len];
        s[len] = s[i];
        s[i] = buf;

        len--;
        i++;
    }

    return s;
}
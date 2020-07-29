//
//  main.c
//  4.3.8
//
//  Created by Yunus Syed on 7/15/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>

#define maxword 50

struct wordcount {
    char *word;
    int number;
    struct wordcount *nextword;
};
typedef struct wordcount *wordptr;

int *getlinef(FILE *fp, char *s);
wordptr getnode(void);

int main(int argc, const char * argv[]) {
    if (argc == 1)
        return 0;
    
    FILE *fp;
    fp = fopen(argv[1], "r");
    char *s;
    wordptr start, w, v;
    start = NULL;

    while (getlinef(fp, s)) {
        int state = 0;
        for (w = start; w != NULL; w = w -> nextword) {
            v = w;
            if (strcmp(w -> word, s)) {
                w -> number ++;
                state = 1;
                break;
            }
        }
        if (state == 0) {
            if (start == NULL)
                start = getnode();
            else {
            w = getnode();
            w -> word = s;
            w -> number = 1;
            v -> nextword = w;
            }
        }
    }

    v = start;
    for (; v != NULL; v = v -> nextword) {
        printf("The word \"%s\" occurs %d times\n", v -> word, v -> number);
    }
 
    return 0;
}

int *getlinef(FILE *fp, char *s) {
    char c;
    while (isspace(c = getc(fp)))
        ;
    if (c != EOF) {
        s = calloc(1, sizeof(char));
        s[0] = c;
    }
    int i = 1;
    while (!isspace(c = getc(fp)) && c != EOF) {
        s = calloc(i+2, sizeof(char));
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    if (i == 1)
        return 0;
    return 1;
}

wordptr getnode(void) {
    return (wordptr) malloc(sizeof(struct wordcount));
}

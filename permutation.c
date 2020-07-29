//
//  main.c
//  perm
//
//  Created by Yunus Syed on 7/11/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void perm(char *s, int a);
void swap(char *s, int i, int j);
void substr(char *s, char *t, int i, int j);

int main() {
    char s[] = "abc";
    perm(s, 0);
    return 0;
}

void perm(char *s, int a) {
    if (a >= strlen(s) - 1) {
        printf("%s\n", s);
        return;
    }
    
    for (int i = a; i < strlen(s); i++) {
        swap(s, a, i);
        perm(s, a+1);
        swap(s, a, i);
    }
}

void swap(char *s, int i, int j) {
    char temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

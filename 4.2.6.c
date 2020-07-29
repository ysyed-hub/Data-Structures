//
//  main.c
//  6
//
//  Created by Yunus Syed on 7/12/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

void tower(int n, char *a, char *b, char *c);
void moves(char *a, char *b);
int top(char *a);

int main() {
    
    int n = 4;
    char a[n], b[n], c[n];
    for (int i = 0; i < n; i++)
        a[i] = b[i] = c[i] = 0;
    tower(n, a, b, c);
    
    return 0;
}

void tower(int n, char *a, char *b, char *c) {
    for (int i = 0; i < n; i++)
        a[i] = n-i;
    
    int state;
    if (n % 2 == 0) {
        printf("Move disk %d from a to b\n", top(a));
        moves(a, b);
        state = 5;
        while (c[n-1] != 1) {
            switch (state) { // p = last destination node
                case 1: // p = a, top a = 1
                    if (top(b) == 0 || (top(b) > top(c) && top(c) != 0)) {
                        printf("Move disk %d from c to b\n", top(c));
                        moves(c, b);
                        state = 4;
                        break;
                    }
                    printf("Move disk %d from b to c\n", top(b));
                    moves(b,c);
                    state = 7;
                    break;
                case 2: // p = a, top b = 1
                    printf("Move disk %d from b to c\n", top(b));
                    moves(b, c);
                    state = 9;
                    break;
                case 3: // p = a, top c = 1
                    printf("Move disk %d from c to a\n", top(c));
                    moves(c,a);
                    state = 1;
                    break;
                case 4: // p = b, top a = 1
                    printf("Move disk %d from a to b\n", top(a));
                    moves(a,b);
                    state = 5;
                    break;
                case 5: // p = b, top b = 1
                    if (top(a) == 0 || (top(a) > top(c) && top(c) != 0)) {
                        printf("Move disk %d from c to a\n", top(c));
                        moves(c,a);
                        state = 2;
                        break;
                    }
                    printf("Move disk %d from a to c\n", top(a));
                    moves(a,c);
                    state = 8;
                    break;
                case 6: // p = b, top c = 1
                    printf("Move disk %d from c to a\n", top(c));
                    moves(c,a);
                    state = 1;
                    break;
                case 7: // p = c, top a = 1
                    printf("Move disk %d from a to b\n", top(a));
                    moves(a,b);
                    state = 5;
                    break;
                case 8: // p = c, top b = 1
                    printf("Move disk %d from b to c\n", top(b));
                    moves(b,c);
                    state = 9;
                    break;
                case 9: // p = c, top c = 1
                    if (top(a) == 0 || (top(a) > top(b) && top(b) != 0)) {
                        printf("Move disk %d from b to a\n", top(b));
                        moves(b,a);
                        state = 3;
                        break;
                    }
                    printf("Move disk %d from a to b\n", top(a));
                    moves(a,b);
                    state = 6;
                    break;
                default:
                    break;
            }
        }
        return;
    }
    
    printf("Move disk %d from a to c\n", top(a));
    moves(a, c);
    state = 9;
    
    while (c[n-1] != 1) {
        switch (state) { // p = last destination node
            case 1: // p = a, top a = 1
                if (top(b) == 0 || (top(b) > top(c) && top(c) != 0)) {
                    printf("Move disk %d from c to b\n", top(c));
                    moves(c, b);
                    state = 4;
                    break;
                }
                printf("Move disk %d from b to c\n", top(b));
                moves(b,c);
                state = 7;
                break;
            case 2: // p = a, top b = 1
                printf("Move disk %d from b to a\n", top(b));
                moves(b, a);
                state = 1;
                break;
            case 3: // p = a, top c = 1
                printf("Move disk %d from c to b\n", top(c));
                moves(c,b);
                state = 5;
                break;
            case 4: // p = b, top a = 1
                printf("Move disk %d from a to c\n", top(a));
                moves(a,c);
                state = 9;
                break;
            case 5: // p = b, top b = 1
                if (top(a) == 0 || (top(a) > top(c) && top(c) != 0)) {
                    printf("Move disk %d from c to a\n", top(c));
                    moves(c,a);
                    state = 2;
                    break;
                }
                printf("Move disk %d from a to c\n", top(a));
                moves(a,c);
                state = 8;
                break;
            case 6: // p = b, top c = 1
                printf("Move disk %d from c to b\n", top(c));
                moves(c,b);
                state = 5;
                break;
            case 7: // p = c, top a = 1
                printf("Move disk %d from a to c\n", top(a));
                moves(a,c);
                state = 9;
                break;
            case 8: // p = c, top b = 1
                printf("Move disk %d from b to a\n", top(b));
                moves(b,a);
                state = 1;
                break;
            case 9: // p = c, top c = 1
                if (top(a) == 0 || (top(a) > top(b) && top(b) != 0)) {
                    printf("Move disk %d from b to a\n", top(b));
                    moves(b,a);
                    state = 3;
                    break;
                }
                printf("Move disk %d from a to b\n", top(a));
                moves(a,b);
                state = 6;
                break;
            default:
                break;
        }
    }
    
    
}

void moves(char *a, char *b) {
    int i, j;
    for (i = 0; a[i] != 0; i++)
        ;
    for (j = 0; b[j] != 0; j++)
        ;
    b[j] = a[i-1];
    a[i-1] = 0;
    
}

int top(char *a) {
    int i;
    for (i = 0; a[i] != 0; i++)
        ;
    if (i == 0)
        return 0;
    return a[i-1];
}

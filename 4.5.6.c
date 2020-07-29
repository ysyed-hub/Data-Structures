//
//  main.c
//  4.5.6
//
//  Created by Yunus Syed on 7/20/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
    char *number;
    struct node *left;
    struct node *right;
};

char *add(char *s, char *t);
int carry(char a, char b, int n);
typedef struct node *nodeptr;
nodeptr getnode(void);
void rever(char *s);
void swap(char *s, int a, int b);

int main() {
    
    nodeptr a, b, c;
    a = getnode();
    b = getnode();
    c = getnode();
    
    a -> number = "0";
    b -> number = "0";
    c -> number = "1";
    
    a -> right = b;
    b -> right = c;
    c -> right = a;
    
    a -> left = c;
    b -> left = a;
    c -> left = b;
    
    nodeptr fib = b;
    for (int i = 1; i < 101; i++) {
        fib -> number = add((fib -> left) -> number, ((fib -> left) -> left) -> number);
        printf("Fib[%d] = %s\n", i, fib -> number);
        fib = fib -> right;
    }
    
    return 0;
}

nodeptr getnode(void) {
    return((nodeptr) malloc (sizeof(struct node)));
}

char *add(char *s, char *t) {
    int i = strlen(s)-1;
    int j = strlen(t)-1;
    int k = 0;
    char *sum;
    sum = (char *) malloc (((i > j) ? i+2 : j+2) * sizeof(char));
    int *carry;
    carry = (int *) malloc(((i > j) ? i+1 : j+1) * sizeof(int));
    
    while (i >= 0 && j >= 0) {
        if (k == 0) {
            sum[k] = (s[i] - '0' + t[j] - '0') % 10 + '0';
            carry[k] = (s[i] - '0' + t[j] - '0') / 10;
        }
        else {
            sum[k] = (s[i] - '0' + t[j] - '0' + carry[k-1]) % 10 + '0';
            carry[k] = (s[i] - '0' + t[j] - '0' + carry[k-1]) / 10;
        }
        k++, i--, j--;
    }
    
    if (i == j) {
        if (carry[k-1] == 1) {
            sum[k] = 1 + '0';
            k++;
            sum[k] = '\0';
        }
        else {
            sum[k] = '\0';
        }
    }
    
    if (i > j) {
        while (i >= 0) {
            sum[k] = (s[i] - '0' + carry[k-1]) % 10 + '0';
            carry[k] = (s[i] - '0' + carry[k-1]) / 10;
            i--;
            k++;
        }
        if (carry[k-1] == 1) {
            sum[k] = 1 + '0';
            k++;
            sum[k] = '\0';
        }
        else {
            sum[k] = '\0';
        }
    }
    
    if (j > i) {
        while (j >= 0) {
            sum[k] = (t[j] - '0' + carry[k-1]) % 10 + '0';
            carry[k] = (t[j] - '0' + carry[k-1]) / 10;
            j--;
            k++;
        }
        if (carry[k-1] == 1) {
            sum[k] = 1 + '0';
            k++;
            sum[k] = '\0';
        }
        else {
            sum[k] = '\0';
        }
    }
    
    rever(sum);
    return sum;
}

int carry(char a, char b, int n) {
    return ((n + a + b - 2 * '0') > 9 ? 1 : 0);
}

void rever(char *s) {
        for (int i = 0; i < strlen(s) / 2; i++)
            swap(s, i, strlen(s) - i - 1);
        return;
}

void swap(char *s, int a, int b) {
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

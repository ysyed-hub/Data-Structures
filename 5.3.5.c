//
//  main.c
//  5.3.5
//
//  Created by Yunus Syed on 7/29/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *right;
    struct node *left;
};

typedef struct node *nodeptr;
nodeptr getnode(void);
nodeptr fib(int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

nodeptr fib(int n) {
    nodeptr p = getnode();
    p -> left = NULL;
    p -> right = NULL;

    if (n > 1) {
        p -> left = fib(n-1);
        p -> right = fib(n-2);
    }
    return p;
}


nodeptr getnode(void) {
    return ((nodeptr) malloc(sizeof(struct node)));
}

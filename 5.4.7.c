//
//  main.c
//  5.4.7
//
//  Created by Yunus Syed on 8/4/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct listnode {
    int info;
    struct listnode *next;
};

struct treenode {
    int info;
    struct treenode *left;
    struct treenode *right;
};

typedef struct treenode *treenodeptr;
typedef struct listnode *listnodeptr;

treenodeptr getnode(void);
listnodeptr getlistnode(void);

listnodeptr makelist(void);
listnodeptr addlistnode(listnodeptr a, int x);
int listsize(listnodeptr a);
treenodeptr maketree(listnodeptr *pa, int n);
treenodeptr findtree(treenodeptr root, int k, int *px, int listsize); // Pointer to kth node
void printtree(treenodeptr root);


int main(int argc, const char * argv[]) {
    
    
    listnodeptr a = makelist();
    listnodeptr *pa = &a;
    int n = listsize(a);
    treenodeptr root = maketree(pa,n);
    printtree(root);
    printf("\n");
    int *px = (int *) malloc(sizeof(int));
    *px = 0;
    printf("%d\n", findtree(root, 2, px, n) -> info);
    
    return 0;
}

void printtree(treenodeptr p) {
    if (p == NULL)
        return;
    printf("%d ", p -> info);
    printtree(p -> left);
    printtree(p -> right);
    return;
}

int listsize(listnodeptr a) {
    int n = 0;
    while (a != NULL) {
        n++;
        a = a -> next;
    }
    return n;
}

listnodeptr makelist(void) {
    listnodeptr root = NULL;
    root = addlistnode(root, 0);
    
    for (int i = 1; i < 20; i++)
        addlistnode(root, i);
    
    return root;
}

listnodeptr addlistnode(listnodeptr a, int x) {
    if (a == NULL) {
        a = getlistnode();
        a -> info = x;
        a -> next = NULL;
        return a;
    }
    
    while (a -> next != NULL) {
        a = a -> next;
    }
    a -> next = getlistnode();
    a = a -> next;
    a -> info = x;
    a -> next = NULL;
    
    return a;
}

treenodeptr maketree(listnodeptr *pa, int n) {
    if (n == 0)
        return NULL;
    // Set root of tree
    treenodeptr p = getnode();
    p -> info = (*pa) -> info;
    (*pa) = (*pa) -> next;
    p -> left = NULL;
    p -> right = NULL;
    n--;
    
    
    // Determine smallest power of 2 that is greater than n
    int x;
    if (n > 0) {
        int x = 1;
        while (x < n)
            x *= 2;
        p -> left = maketree(pa, (x/2 == 0) ? 1 : x/2); // If n = 1, right son = NULL
        p -> right = maketree(pa, (x/2 == 0) ? 0: n - x/2);
    }
    return p;
}

treenodeptr findtree(treenodeptr p, int k, int *px, int listsize) {
    if (p == NULL || k > listsize)
        return NULL;
    (*px)++;
    if (*px == k)
        return p;
    treenodeptr q = findtree(p -> left, k, px, listsize);
    treenodeptr r = findtree(p -> right, k, px, listsize);
    if (q != NULL || r != NULL)
        return((q == NULL) ? r : q);
    
    return NULL;
}

listnodeptr getlistnode(void) {
    return ((listnodeptr) malloc(sizeof(struct listnode)));
}

treenodeptr getnode(void) {
    return ((treenodeptr) malloc(sizeof(struct treenode)));
}

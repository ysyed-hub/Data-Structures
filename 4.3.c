//
//  main.c
//  4.3
//
//  Created by Yunus Syed on 7/15/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node *nodeptr;

struct queue {
    nodeptr front, rear;
};
typedef struct queue *qptr;

int emptystack(nodeptr ps); // 4.3 #1
int emptyqueue(qptr pq); // 4.3 #2
void push(nodeptr ps, int x); // 4.3 #1
void pop(nodeptr ps, int *py); // 4.3 #1
void insert(qptr pq, int x); // 4.3 #2
void remov(qptr pq, int *py); // 4.3 #2
void listswap(nodeptr pl, int m, int n); // 4.3 #5


nodeptr getnode(void);

int main(int argc, const char * argv[]) {
    int *py = (int *) malloc(sizeof(int));
    
    
    return 0;
}

nodeptr getnode(void) {
    nodeptr p;
    p = (nodeptr) malloc(sizeof(struct node));
    return(p);
}

int emptystack(nodeptr ps) {
    return((ps == NULL) ? 1 : 0);
}

void push(nodeptr ps, int x) {
    nodeptr p;
    p = getnode();
    p -> info = x;
    p -> next = ps;
    ps = p;
}

void pop(nodeptr ps, int *py) {
    if (emptystack(ps)) {
        printf("Underflow");
        return;
    }
    
    nodeptr p = ps;
    *py = p -> info;
    ps = p -> next;
    p = NULL;
    
}

int emptyqueue(qptr pq) {
    return ((pq -> front == NULL) ? 1 : 0);
}

void insert(qptr pq, int x) {
    nodeptr p;
    p = getnode();
    p -> info = x;
    p -> next = NULL;
    if (emptyqueue(pq)) {
        pq -> front = p;
        pq -> rear = p;
    }
    (pq -> rear) -> next = p;
    pq -> rear = p;
}

void remov(qptr pq, int *py) {
    nodeptr p, q;
    q = NULL;
    if (emptyqueue(pq)) {
        printf("Underflow");
        return;
    }
    for (p = (pq -> front); p != (pq -> rear); p = p -> next)
        q = p;
    if (q == NULL) {
        *py = (pq->front)->info;
        free(pq->front);
        return;
    }
    *py = (pq -> rear) -> info;
    (pq -> rear) = q;
    free(p);
}

void listswap(nodeptr pl, int m, int n) {
    nodeptr p, q;
    int temp;
    int i;
    for (i = 1, p = pl; i < m; p = p->next, i++)
        if (p == NULL)
            return;
    temp = p -> info;
    q = p;
    for(; i < n; q = q->next, i++)
        if (q == NULL)
            return;
    p -> info = q -> info;
    q -> info = temp;
        
}

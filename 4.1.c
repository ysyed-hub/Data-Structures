//
//  main.c
//  4.1
//
//  Created by Yunus Syed on 7/14/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include <stdio.h>

#define maxqueue 100

struct queue {
    int items[maxqueue];
    int front, rear;
};

void remvandtest(struct queue *pq, int *px, int *pund); // 4.1 #1
int remv(struct queue *pq);
int empty(struct queue *pq);

int main() {
    
    struct queue q;
    q.front = q.rear = maxqueue - 1;
    int x, und;
    struct queue *pq = &q;
    und = empty(pq);
    
    printf("Hello, World!\n");
    return 0;
}

int empty(struct queue *pq) {
    return((pq -> front == pq -> rear) ? 1 : 0);
}

int remv(struct queue *pq) {
    if (empty(pq)) {
        printf("queue underflow");
        return 1;
    }
    if (pq -> front == maxqueue - 1)
        pq -> front = 0;
    else
        (pq -> front)++;
    return (pq -> items[pq->front]);
}

void remvandtest(struct queue *pq, int *px, int *pund) {
    if (empty(pq)) {
        *pund = 1;
        return;
    }
    *pund = 0;
    *px = remv(pq);
}

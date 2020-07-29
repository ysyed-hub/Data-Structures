//
//  main.c
//  3.2.3
//
//  Created by Yunus Syed on 7/10/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include <stdio.h>

int comm(int x, int y); // 3.2.3
int gfib(int f0, int f1, int n); // 3.2.4
int gfibi(int f0, int f1, int n); // 3.2.4
int seq(int n); // 3.2.5

int main() {
    
    printf("%d\n", seq(10));
    return 0;
}

int seq(int n) {
    if (n == 2)
        return 3;
    if (n == 1)
        return 2;
    return (seq(n-1) + seq(n-2));
}

int gfibi(int a, int b, int n) {
    
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    
    int low, high, x, i;
    i = 2;
    low = a;
    high = b;

    while (i++ <= n) {
        x = low;
        low = high;
        high = x + low;
    }
    return high;
}

int gfib(int a, int b, int n) {
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return (gfib(a,b,n-1) + gfib(a,b,n-2));
}

int comm(int x, int y) {
    if (x < y || y < 0)
        return 0;
    if (y == 0)
        return 1;
    return (comm(x-1, y) + comm(x-1, y-1));
}

#include<bits/stdc++.h>

int parent(int x){
    if(x == par[x]) return x;
    par[x] = parent(par[x]);
    return par[x];
}

void join(int a, int b){
    int x = parent(a);
    int y = parent(b);
    if(x==y) return;
    par[y] = x;
    return;
}
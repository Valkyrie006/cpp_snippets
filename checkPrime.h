#include <bits/stdc++.h>
bool isPrime(long long x){
    for(int i = 2 ; i <= x/i ; i++){
        if(x%i == 0) return false;
    }
    return true;
}
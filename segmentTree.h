#include <bits/stdc++.h>
using namespace std;

class segtree{
private:
    int size;
    vector<long long> v;
    
    //For range sum queries...this will be 0
    //For range minimum queries...make it greater than maximum element of array
    //For range maximum queries...make it smaller than minimum element of array
    long long baseValue = 0;
    // long long baseValue = INT64_MAX;
    // long long baseValue = INT64_MIN;
    
    //Change this function according to question
    long long func(long long a, long long b){
        long long ans = a+b;
        // long long ans = min(a,b);
        // long long ans = max(a,b);
        return ans;
    }
 
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)a.size()){
                v[x] = a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx); 
        v[x] = func(v[2*x+1], v[2*x+2]);
        return;
    }
 
    void set(int i, int val, int x, int lx, int rx){
        if(rx - lx == 1){
            v[x] = val;
            return;
        }
 
        int m = (lx+rx)/2;
        if(i < m){
            set(i, val, 2*x+1, lx, m);
        }
        else set(i, val, 2*x+2, m, rx);
        
        v[x] = func(v[2*x+1], v[2*x+2]);
    }
 
    long long get(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx) return baseValue;
        else if(lx >= l && rx <= r) return v[x];
        
        int m = (lx+rx)/2;
        long long ans1 = get(l, r, 2*x+1, lx, m);
        long long ans2 = get(l, r, 2*x+2, m, rx);
        return func(ans1, ans2);
    }
 
public:
    segtree(vector<int> &a){
        size = 1;
        int n = (int)a.size();
        while(size < n) size<<=1;
        v.assign(2*size, baseValue);
        build(a,0,0,size);
 
    }
 
    void set(int i, int val){   
        set(i, val, 0, 0, size);
        return;
    }
 
    long long get(int l, int r){
        return get(l, r, 0, 0, size);
    }
 
};
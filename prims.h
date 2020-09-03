#include<bits/stdc++.h>
using namespace std;

// ---------------------------PRIMS----------------------//
typedef pair<int,int> vpi;
void mst(vector<vpi> v[],int N, vector<int> &par){
	priority_queue< vpi, vector<vpi>, greater<vpi> > pq;
	vector<int> auxilary(N+1,INT_MAX);
	vector<bool> inTree(N+1,false);
	
	pq.push({0,1});
	auxilary[1] = 0;
	
	while(!pq.empty()){
		int x = pq.top().second;
		pq.pop();
		inTree[x] = true;
		
		for(auto p:v[x]){
			int y = p.first;
			int w = p.second;
			if(!inTree[y] && auxilary[y] > w){
				auxilary[y] = w;
				pq.push({w,y});
				par[y] = x; 
			}
			
		}
	}
	return;
}
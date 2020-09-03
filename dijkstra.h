#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pqi;
// initialise dist vector as max_int for every element
//  <--------------- DIJKSTRA------------------>
void shortest(vector<pair<int,int>> v[], int source, vector<long long> &dist){
	priority_queue< pqi, vector<pqi>, greater<pqi> > pq;
	pq.push({0LL,source});
	dist[source] = 0;
	
	while(!pq.empty()) {
		int x = pq.top().second;
		pq.pop();
		for(auto p:v[x]){
			int y = p.first;
			long long w = p.second;
			
			if(dist[y] > dist[x] + w){
				dist[y] = dist[x]+w;
				pq.push({dist[y],y});
			}
		}
	}
	return;
}
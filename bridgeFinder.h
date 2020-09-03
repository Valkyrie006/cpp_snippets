#include<bits/stdc++.h>
using namespace std;
class bridgefinder{
	vector<bool> visited;
	vector<int> entry, mintime;
	int counter;
	
	void whatToDo(int x, int y){
		ans.push_back({x,y});
	}
	
	void dfs_this(vector<int> v[], int node, int parent){
		visited[node] = true;
		entry[node] = mintime[node] = counter++;
		for(int i:v[node]){
			if(i==parent) continue;
			if(visited[i]){
				mintime[node] = min(mintime[node], entry[i]);
			}
			else{
				dfs_this(v,i,node);
				mintime[node] = min(mintime[node], mintime[i]);
				if(mintime[i] > entry[node]){
					whatToDo(i,node);
				}
			}
		}
		return;
	}
public:
	vector<pair<int,int>> ans;
	bridgefinder(vector<int> v[], int N){
		visited.assign(N+1,false);
		entry.assign(N+1,-1);
		mintime.assign(N+1,-1);
		ans.clear();
		counter = 0;
		dfs_this(v,1,-1);
	}
};
#include<bits/stdc++.h>

using namespace std;
// ---------------------------Kruskal----------------------//
class kruskal{
	vector<int> mypar;
	int parent(int x){
	    if(x==mypar[x]) return x;
	    mypar[x] = parent(mypar[x]);
	    return mypar[x];
	}
	
	// returns true if they already belong to same family
	bool join(int a, int b){
	    int x= parent(a);
	    int y= parent(b);
	    if(x==y) return true;
	    mypar[y] = x;
	    return false;
	}
	
	void start(vector<pair<int,pair<int,int>>> &edges){
		for(int i=0 ; i<(int)edges.size() ; i++){
			auto e = edges[i];
			if(!join(e.second.first, e.second.second)){
				cost += e.first;
				ans.push_back({e.second.first, e.second.second});
			}
		}
	}
public:
	vector<pair<int,int>> ans;
	long long cost;
	kruskal(vector<pair<int,pair<int,int>>> &edges){
		mypar.assign(200010,0);
		ans.clear();
		cost = 0;
		for(int i=0 ; i<=200000 ; i++) mypar[i] = i;
		sort(edges.begin(), edges.end());
		start(edges);
	}
};
#include "bits/stdc++.h"
using namespace std; 
const int inf = 1e7;
int main() 
{
	int n,m;  // n is the number of vertices and m is the number of edges 
	cin>>n>>m;
	//initializing every node to infinity 
	vector<int> dist(n+1, inf);
	// pair because of weight and declaring graph 
	vector<vector<pair<int, int>>> graph(n+1);
	// taking input 
	for(int i=0;i<m;i++){
		int u,v,w; 
		cin>>u>>v>>w; 
		graph[u].push_back({v,w}); 
		graph[v].push_back({u,w});
		
	}
	// taking source 
	int source; cin>> source;
	//always ininitialize source to 0
	dist[source] = 0;
	// declaring set
	set<pair<int, int>> s;
	//{wt, vertex)
	// initializing source into set 
	s.insert({0,source}); 
	
	//itterating the whole graph 
	while(!s.empty()){
	auto x=	*(s.begin());
	s.erase(x);
		for(auto it: graph[x.second])
		{
			if(dist[it.first] > dist[x.second] + it.second) 
			{
				//erasign infinity or old distance 
				s.erase({dist[it.first],it.first});
				//saving new distance 
				dist[it.first] = dist[x.second]+it.second; 
				s.insert({dist[it.first], it.first});
				
			}
		
		}
	}
	// showing the path 
	for (int i=1;i<n;i++)
	{
		if(dist[i]<inf)
		{
			cout<<dist[i]<<" ";			
		} 
		else
		{
			cout<<-1<<" ";
		}	
	}
}

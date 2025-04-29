#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#define DIRECTED 0
#define UNDIRECTED 1
using namespace std;
class DisjointSets
{
	public:
		int *parent, *Rank;
		int n;
		
		DisjointSets(int n)
		{
			this->n = n;
			parent = new int[n+1];
			Rank = new int[n+1];
			for(int i = 0; i <= n ; i++)
			{
				Rank[i] = 0;
				parent[i] = i;
			}
		}
		~DisjointSets()
		{
			delete[] parent;
			delete[] Rank;
		}
		int Find(int u)
		{
			if(u != parent[u]) parent[u] = Find(parent[u]);
			return parent[u];
		}
		void Union(int x, int y)
		{
			x = Find(x);
			y = Find(y);
			if(Rank[x] > Rank[y]) parent[y] = x;
			else if(Rank[x] < Rank[y]) parent[x] = y;
			else
			{
				Rank[y]++;
				parent[y] = x;
			}
		}
};
class Edge
{
	public:
		int DestinationVertexID;
		int weight;
		
		Edge() {}
		Edge(int destVID, int w) {DestinationVertexID = destVID;weight = w;}
		void setEdgeValues(int destVID, int w) {DestinationVertexID = destVID;weight = w;}
		void setWeight(int w) {weight = w;}
		int getDestinationVertexID() {return DestinationVertexID;}
		int getWeight() {return weight;}
};
class Vertex 
{
	public:
		int state_id;
		string state_name;
		list<Edge> edgeList;
		
		Vertex() {state_id = 0;state_name = "";}
		Vertex(int id, string sname) {state_id = id;state_name = sname;}
		int getStateID() {return state_id;}
		string getStateName() {return state_name;}
		void setID(int id) {state_id = id;}
		void setStateName(string sname) {state_name = sname;}
		list < Edge > getEdgeList() {return edgeList;}
		void printEdgeList()
		{
			cout << "[";
			for (auto it = edgeList.begin(); it != edgeList.end(); it++) cout << it -> getDestinationVertexID() << "(" << it -> getWeight() << ") --> ";
			cout << "]";
			cout << endl;
		}
		void updateVertexName(string sname) {state_name = sname;cout << "Vertex Name Updated Successfully";}
};
template<int n>
class Graph 
{
	vector<Vertex> vertices;
	public:
		bool checkIfVertexExistByID(int vid)
		{
			for (int i = 0; i < vertices.size(); i++) if (vertices.at(i).getStateID() == vid) return true;
			return false;
		}
		void addVertex(Vertex newVertex)
		{
			if (checkIfVertexExistByID(newVertex.getStateID())) cout << "Vertex with this ID already exist" << endl;
			else
			{
				vertices.push_back(newVertex);
				cout << "New Vertex Added Successfully" << endl;
			}
		}
		Vertex getVertexByID(int vid) 
		{
			Vertex temp;
			for (int i = 0; i < vertices.size(); i++) 
			{
				temp = vertices.at(i);
				if (temp.getStateID() == vid) return temp;
			}
			return temp;
		}
		bool checkIfEdgeExistByID(int fromVertex, int toVertex) 
		{
			Vertex v = getVertexByID(fromVertex);
			for (auto it = v.edgeList.begin(); it != v.edgeList.end(); it++) if (it->getDestinationVertexID() == toVertex) return true;
			return false;
		}
		void updateVertex(int oldVID, string vname) 
		{
			if (checkIfVertexExistByID(oldVID))
			{
				for (int i = 0; i < vertices.size(); i++) 
				if (vertices.at(i).getStateID() == oldVID) {vertices.at(i).setStateName(vname);break;}
				cout << "Vertex(State) Updated Successfully " << endl;
			}
		}
		void addEdgeByID(int fromVertex, int toVertex, int weight) 
		{
			bool check1 = checkIfVertexExistByID(fromVertex);
			bool check2 = checkIfVertexExistByID(toVertex);
			bool check3 = checkIfEdgeExistByID(fromVertex, toVertex);
			if ((check1 && check2 == true)) 
			{
				if (check3 == true)
				cout << "Edge between " << getVertexByID(fromVertex).getStateName() << "(" << fromVertex << ") and " << getVertexByID(toVertex).getStateName() 
				<< "(" << toVertex << ") Already Exist" << endl;
				else 
				{
					for (int i = 0; i < vertices.size(); i++)
					{
						if (vertices.at(i).getStateID() == fromVertex)
						{
							Edge e(toVertex, weight);
							vertices.at(i).edgeList.push_back(e);
						}
						else if (vertices.at(i).getStateID() == toVertex && n)
						{
							Edge e(fromVertex, weight);
							vertices.at(i).edgeList.push_back(e);
						}
					}
					cout << "Edge between " << fromVertex << " and " << toVertex << " added Successfully" << endl;
				}
			} 
			else cout << "Invalid Vertex ID entered.";
		}
		void updateEdgeByID(int fromVertex, int toVertex, int newWeight) 
		{
			bool check = checkIfEdgeExistByID(fromVertex, toVertex);
			if (check) 
			{
				for (int i = 0; i < vertices.size(); i++) 
				{
					if (vertices.at(i).getStateID() == fromVertex) 
					{
						for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) 
						{
							if (it -> getDestinationVertexID() == toVertex) {it -> setWeight(newWeight);break;}
						}
					} 
					else if (vertices.at(i).getStateID() == toVertex) 
					{
						for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) 
						{
							if (it -> getDestinationVertexID() == fromVertex) {it -> setWeight(newWeight);break;}
						}
					}
				}
				cout << "Edge Weight Updated Successfully " << endl;
			} 
			else cout << "Edge between " << getVertexByID(fromVertex).getStateName() << "(" << fromVertex << ") and " 
			<< getVertexByID(toVertex).getStateName() << "(" << toVertex << ") DOES NOT Exist" << endl;
		}
		void deleteEdgeByID(int fromVertex, int toVertex) 
		{
			bool check = checkIfEdgeExistByID(fromVertex, toVertex);
			if (check) 
			{
				for (int i = 0; i < vertices.size(); i++)
				{
					if (vertices.at(i).getStateID() == fromVertex) 
					{
						for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) 
						{
							if (it -> getDestinationVertexID() == toVertex) {vertices.at(i).edgeList.erase(it);break;}
						}
					}
					if (vertices.at(i).getStateID() == toVertex) 
					{
						for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) 
						{
							if (it -> getDestinationVertexID() == fromVertex) {vertices.at(i).edgeList.erase(it);break;}
						}
					}
				}
				cout << "Edge Between " << fromVertex << " and " << toVertex << " Deleted Successfully." << endl;
			}
		}	
		void deleteVertexByID(int vid) 
		{
			int vIndex = 0;
			for (int i = 0; i < vertices.size(); i++) if (vertices.at(i).getStateID() == vid) vIndex = i;
			for (int i = 0; i < vertices.size(); i++) 
			{
				for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++)
				{
					if (it -> getDestinationVertexID() == vid) {vertices.at(i).edgeList.erase(it);break;}
				}
			}
			vertices.erase(vertices.begin() + vIndex);
			cout << "Vertex Deleted Successfully" << endl;
		}
		void getAllNeigborsByID(int vid) 
		{
			cout << getVertexByID(vid).getStateName() << " (" << getVertexByID(vid).getStateID() << ") --> ";
			for (int i = 0; i < vertices.size(); i++) 
			{
				if (vertices.at(i).getStateID() == vid) 
				{
					cout << "[";
					for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) 
					{
						cout << it -> getDestinationVertexID() << "(" << it -> getWeight() << ") --> ";
					}
					cout << "]";
				}
			}
			
		}
		void printGraph() 
		{
			for (int i = 0; i < vertices.size(); i++) 
			{
				Vertex temp;
				temp = vertices.at(i);
				cout << temp.getStateName() << " (" << temp.getStateID() << ") --> ";
				temp.printEdgeList();
			}
		}
		void BFS(int x)
		{
			bool visited[vertices.size()] = {0};
			visited[x] = true;
			queue<int> q;
			q.push(x);
			while(!q.empty())
			{	
				x = q.front();
				cout<<x<<" ";
				q.pop();
				for(auto i = vertices[x].edgeList.begin(); i != vertices[x].edgeList.end() ; i++)
				{
					if(!visited[i->DestinationVertexID])
					{
						visited[i->DestinationVertexID] = true;
						q.push(i->DestinationVertexID);
					}
				}
			}
		}
		void DFS1(int x)
		{
			bool visited[vertices.size()] = {0};
			stack<int> s;
			visited[x] = true;
			s.push(x);
			while(!s.empty())
			{
				x = s.top();	
				cout<<x<<" ";
				s.pop();
				for(auto i = vertices[x].edgeList.begin(); i != vertices[x].edgeList.end() ; i++)
				{
					if(!visited[i->DestinationVertexID])
					{
						visited[i->DestinationVertexID] = true;
						s.push(i->DestinationVertexID);
					}
				}
			}
		}
		void DFSRecur(int x, bool visited[])
		{
			visited[x] = true;
			cout << x << " ";
			for(auto i = vertices[x].edgeList.begin(); i != vertices[x].edgeList.end() ; i++)
			{
				if(!visited[i->DestinationVertexID])
				 DFSRecur(i->DestinationVertexID,visited);
			}
		}
		void primMST(int source)
		{
		    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> > pq;
		    vector<int> key(vertices.size(),INT_MAX);
		    vector<int> parent(vertices.size(),-1);
		    vector<bool> inMST(vertices.size(),false);
		    int MSTWeight = 0;
		    pq.push(make_pair(0,source));
		    key[source] = 0;
		    while(!pq.empty())
			{
		        int u = pq.top().second, v, weight;
		        pq.pop();	
		        if(inMST[u]) continue;
		        inMST[u] = true;
		        for(auto i = vertices[u].edgeList.begin(); i != vertices[u].edgeList.end() ; i++)
		        {
		            v = i->DestinationVertexID;
		            weight = i->weight;
		            if(!inMST[v] && key[v]> weight)
					{
		                key[v] = weight;
		                pq.push(make_pair(key[v],v));
		                parent[v] = u;
		            }
		        }
		        if(!inMST[pq.top().second])cout << "Edge " << "(" << parent[pq.top().second] << ", "  << pq.top().second << ") cost: " << pq.top().first << '\n';
		    }
		    for(int i=0;i<vertices.size();i++) MSTWeight += key[i];
		    cout << "Minimun Cost = " << MSTWeight;
		}
		void KruskalMST()
		{
			int MSTWeight = 0;
			DisjointSets ds(vertices.size());
			int i = 0;
			while(i < vertices.size() - 1)
			{
				int min = INT_MAX, a = -1, b = -1;
				for(int j = 0; j < vertices.size(); j++)
				{
					for(auto k = vertices[j].edgeList.begin(); k != vertices[j].edgeList.end(); k++)
					{
						if(ds.Find(j) != ds.Find(k->DestinationVertexID) && k->weight < min)
						{
							min = k->weight;
							a = j;
							b = k->DestinationVertexID;
						}
					}
				}
				cout << "Edge " << i << ": (" << a << ", "  << b << ") cost: " << min << '\n';
				ds.Union(a,b);
				MSTWeight += min;
				i++;
			}
			cout << "Minimum Cost = " << MSTWeight << '\n';
		}
		void Dijkstra(int source)
		{
			priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> > pq;
			vector<int> dist(vertices.size(), INT_MAX);
			pq.push(make_pair(source, 0));
			dist[source] = 0;
			while (!pq.empty()) 
			{
				int u = pq.top().first;
				pq.pop();
				for(auto i = vertices[u].edgeList.begin(); i != vertices[u].edgeList.end() ; i++)
				{
					int v = i->DestinationVertexID;
				    int weight = i->weight;
					if (dist[v] > dist[u] + weight)
					{
						dist[v] = dist[u] + weight;
						pq.push(make_pair(v, dist[v]));
					}
				}
			}
			printf("Vertex Distance from Source\n");
			for (int i = 0; i < vertices.size(); ++i) printf("%d \t\t %d\n", i, dist[i]);
		}
		void TopologicalSort()
		{
			stack<int> s;
			vector<bool> visited(vertices.size(), false);
			for(int i = 0 ; i < vertices.size(); i++) if(!visited[i]) TopologicalSort(i, visited, s);
			while(!s.empty())
			{
				cout << s.top() << " ";
				s.pop();
			}
		}
		void TopologicalSort(int v, vector<bool> &visited, stack<int> &s)
		{
			visited[v] = true;
			for(auto i = vertices[v].edgeList.begin(); i != vertices[v].edgeList.end(); i++)
			{
				if(!visited[i->DestinationVertexID])
				TopologicalSort(i->DestinationVertexID, visited, s);
			}
			s.push(v);
		}
};
int main() 
{	
	Graph<UNDIRECTED> G3;
	string arr[10] = {"A","B","C","D","E","F","G","H","I","J"};
//	for(int i = 0 ; i < 10 ; i++) G3.addVertex(Vertex(i,arr[i]));
//	for(int i = 0 ; i < 10 ; i++) G3.addEdgeByID(rand()%10,rand()%10,rand()%20+1);
//	G3.addEdgeByID(0,1,1);
	for(int i = 0 ; i < 6 ; i++)G3.addVertex(Vertex(i,arr[i]));
	G3.addEdgeByID(0,1,10);
	G3.addEdgeByID(0,3,20);
	G3.addEdgeByID(0,5,2);
	G3.addEdgeByID(1,3,5);
	G3.addEdgeByID(1,2,3);
	G3.addEdgeByID(2,4,15);
	G3.addEdgeByID(3,4,11);
	G3.addEdgeByID(3,5,10);
	G3.addEdgeByID(4,5,3);
	G3.printGraph();
	cout << "\nBFS: ";G3.BFS(1);
	
	cout << "\nDFS: ";G3.DFS1(1);
	bool visited[10]= {0};
	cout << "\nDFSRecur: "; G3.DFSRecur(1,visited);
	
	cout << "\n\nPrim: " << endl;
	G3.primMST(2);
	
	cout << "\n\nKruskal: \n";
	G3.KruskalMST();
	
	cout << "\n\nDijkstra: \n";
	G3.Dijkstra(0);
	
	cout << "\n\nTopological Sort \n";
	G3.TopologicalSort();
}

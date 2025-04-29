#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#define DIRECTED 0
#define UNDIRECTED 1
using namespace std;
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
			bool check = checkIfVertexExistByID(newVertex.getStateID());
			if (check) cout << "Vertex with this ID already exist" << endl;
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
			list < Edge > e;
			e = v.getEdgeList();
			for (auto it = e.begin(); it != e.end(); it++) if (it -> getDestinationVertexID() == toVertex) return true;
			return false;
		}
		void updateVertex(int oldVID, string vname) 
		{
			bool check = checkIfVertexExistByID(oldVID);
			if (check) 
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
			bool visited[vertices.size()];
			for(int i=0; i<vertices.size(); i++) visited[i] = false;
			queue<int> q;
			visited[x] = true;
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
		void DFS(int x)
		{
			bool visited[vertices.size()];
			for(int i=0; i<vertices.size(); i++) visited[i] = false;
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
		void primMST()
		{
	    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> > pq;
	    vector<int> key(vertices.size(),INT_MAX);
	    vector<int> parent(vertices.size(),-1);
	    vector<bool> inMST(vertices.size(),false);
	    pq.push(make_pair(0,0));
	    key[0] = 0;
	    while(!pq.empty())
		{
	        int u = pq.top().second;
	        pq.pop();
	        inMST[u] = true;
	        for(auto i = vertices[u].edgeList.begin(); i != vertices[u].edgeList.end() ; i++)
	        {
	            int v = i->DestinationVertexID;
	            int weight = i->weight;
	            if(!inMST[v] && key[v]> weight)
				{
	                key[v] = weight;
	                pq.push(make_pair(key[v],v));
	                parent[v] = u;
	            }
	        }
	    }
	    for(int i=1;i<vertices.size();i++){
	        cout << parent[i] << " - "  << i << endl;
	    }
	}
};
int main() 
{
	//Task 1 Directed
	cout << "---------------TASK 1 DIRECTED---------------" << endl;
	Graph<DIRECTED> G2;
	G2.addVertex(Vertex(0,"Ahmed"));
	G2.addVertex(Vertex(1,"Bilal"));
	G2.addVertex(Vertex(2,"Danish"));
	G2.addEdgeByID(0,2,10);
	G2.addEdgeByID(0,1,13);
	cout << endl;
	G2.printGraph();
	cout << endl;
	G2.deleteVertexByID(1);
	cout << endl;
	G2.printGraph();
	cout << endl;
	
	//Task 1 Undirected
	cout << "---------------TASK 1 UNDIRECTED---------------" << endl;
	Graph<UNDIRECTED> G1;
	G1.addVertex(Vertex(0,"Ahmed"));
	G1.addVertex(Vertex(1,"Bilal"));
	G1.addVertex(Vertex(2,"Danish"));
	G1.addEdgeByID(0,2,10);
	G1.addEdgeByID(0,1,13);
	cout << endl;
	G1.printGraph();
	cout << endl;
	G1.deleteVertexByID(1);
	cout << endl;
	G1.printGraph();
	
	//Task 2
	cout << "\n\n" << "---------------TASK 2---------------" << endl;
	Graph<UNDIRECTED> G3;
	string arr[10] = {"A","B","C","D","E","F","G","H","I","J"};
	for(int i = 0 ; i < 10 ; i++) G3.addVertex(Vertex(i,arr[i]));
	for(int i = 0 ; i < 10 ; i++) G3.addEdgeByID(rand()%10,rand()%10,rand()%20+1);
	G3.addEdgeByID(0,1,1);
	G3.printGraph();
	cout << "BFS: ";G3.BFS(1);
	
	//Task 3
	cout << "\n\n" << "---------------TASK 3---------------" << endl;
	cout << "DFS: ";G3.DFS(1);
	
	//Task 4
	cout << "\n\n" << "---------------TASK 4---------------" << endl;
	cout << "Prim: " << endl;
	G3.primMST();
}

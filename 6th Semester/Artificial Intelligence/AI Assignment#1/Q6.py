import networkx as nx
from matplotlib import pyplot as plt
from queue import PriorityQueue

# Returns the actual cost of the path
def path_cost(pa):
    cost=0
    if pa[0]=="source and destination are same":
      return(cost)
    for i in range(1,len(pa)):
            cost=cost+(G[pa[i-1]][pa[i]]['weight'])  
    return (cost)

def BFS(G,so,ds):
    if so==ds:
        return("source and destination are same",ds)
    visited = []
    queue = [[so]]
    while queue:
        pathway=queue.pop(0)
        node=pathway[-1]
        if node not in visited:
            for child in G[node]:
                new_pathway= list(pathway)
                new_pathway.append(child)
                queue.append(new_pathway)
                if child==ds:
                    return new_pathway
            visited.append(node)

def UCS(G,so,ds):
    if so==ds:
        return("source and destination are same",ds) 
    visited = []                 
    qu = PriorityQueue()       
    qu.put((0, so, [so]))             
    while not qu.empty(): 
        cost, currentnode, pathway = qu.get()
        visited.append(currentnode)   
        if currentnode==ds:     
            return pathway             
        else:
            for child in G[currentnode]:
                if child not in visited:
                    qu.put((path_cost(pathway+[child]),child,pathway+[child]))

def GBFS(G,so,ds):
    if(so==ds):
        return("source and destination are same",ds) 
    qu = PriorityQueue()                                          
    qu.put((h_v(so),so,[so]))              
    while not qu.empty():
       heuristiccost,currentnode,pathway = qu.get()
       if currentnode==ds:    
            return pathway             
       else:
            for child in G[currentnode]:
                    qu.put((h_v(child),child,pathway+[child])) 

def DLS(G,currentnode,ds,visited,limit,d,pathway):
    visited.append(currentnode)
    if currentnode==ds:
      global path_way
      path_way=pathway
      global found
      found=True
      return(True)
    if (limit<=d):
      return(False)
    d=d+1
    for child in G[currentnode]:
        if child not in visited:
            DLS(G,child,ds,visited,limit,d,pathway+[child])

def IDDFS(G,so,ds):
   for limit in range(1,30):
     if found==False:
       DLS(G,so,ds,[],limit,0,[so])

# Heuristics Values
def h_v(n):
    if n=="arad":
     return(366)
    elif n=="bucharest":
     return(0)
    elif n=="craiova":
     return(160)
    elif n=="drobeta":
     return(242)
    elif n=="eforie":
     return(161)
    elif n=="fagaras":
     return(176)
    elif n=="giurgiu":
     return(77)
    elif n=="hirsova":
     return(151)
    elif n=="iasi":
     return(226)
    elif n=="lugoj":
     return(244)
    elif n=="mehadia":
     return(241)
    elif n=="neamt":
     return(234)
    elif n=="oradea":
     return(380)
    elif n=="pitesti":
     return(100)
    elif n=="rimnicu vilcea":
     return(193)
    elif n=="sibiu":
     return(253)
    elif n=="timisoara":
     return(329)
    elif n=="urziceni":
     return(80)
    elif n=="vaslui":
     return(199)
    elif n=="zerind":
     return(374)    

found=False
def compare(G, s, t):
    a1=BFS(G,s,t)
    print('BFS Caculated!')
    a2=UCS(G,s,t)
    print('UCS Caculated!')
    a3=GBFS(G,s,t)
    print('GBFS Caculated!')
    IDDFS(G,s,t)
    print('IDDFS Caculated!')
    que=PriorityQueue()
    que.put((path_cost(a1),a1,"BFS"))
    que.put((path_cost(a2),a2,"UCS"))
    que.put((path_cost(a3),a3,"GBFS"))
    que.put((path_cost(path_way),path_way,"IDDFS"))
    while not que.empty():
        cost,path,algo=que.get()
        print("Algorithm ",algo," gives cost ",cost," and pathway is ",path)



# Main Code start here
G=nx.Graph()
G.add_nodes_from(["arad","bucharest","craiova","drobeta","eforie","fagaras","giurgiu","hirsova","iasi","lugoj","mehadia","neamt","oradea","pitesti","rimnicu vilcea","sibiu","timisoara","urziceni","vaslui","zerind"])

G.add_edge("oradea","zerind",weight=71)
G.add_edge("zerind","arad",weight=75)
G.add_edge("arad","timisoara",weight=118)
G.add_edge("timisoara","lugoj",weight=111)
G.add_edge("lugoj","mehadia",weight=70)
G.add_edge("mehadia","drobeta",weight=75)
G.add_edge("drobeta","craiova",weight=120)
G.add_edge("craiova","pitesti",weight=138)
G.add_edge("craiova","rimnicu vilcea",weight=146)
G.add_edge("rimnicu vilcea","pitesti",weight=97)
G.add_edge("rimnicu vilcea","sibiu",weight=80)
G.add_edge("oradea","sibiu",weight=151)
G.add_edge("arad","sibiu",weight=140)
G.add_edge("sibiu","fagaras",weight=99)
G.add_edge("pitesti","bucharest",weight=101)
G.add_edge("fagaras","bucharest",weight=211)
G.add_edge("urziceni","bucharest",weight=85)
G.add_edge("giurgiu","bucharest",weight=90)
G.add_edge("urziceni","hirsova",weight=98)
G.add_edge("hirsova","eforie",weight=86)
G.add_edge("urziceni","vaslui",weight=142)
G.add_edge("vaslui","iasi",weight=92)
G.add_edge("iasi","neamt",weight=87)


# Compares the 4 searches
compare(G, 'arad', 'bucharest')
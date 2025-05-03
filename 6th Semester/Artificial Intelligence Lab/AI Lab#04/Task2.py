'''Implement DFS on graph and tree.'''


tree = ['A', ['B', [], []], ['C', ['D', [], ['E', [], []]], []]]

def dfs(tree, visited=set()):
    if tree:
        root, left, right = tree
        visited.add(root)
        print(root, end=' ')
        dfs(left, visited)
        dfs(right, visited)
dfs(tree)

print('\n')

graph = {
    'A': ['B', 'C'],
    'B': [],
    'C': ['D', 'E'],
    'D': [],
    'E': []
}

def dfs(graph, start, visited=set()):
    visited.add(start)
    print(start, end=' ')
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)
dfs(graph, 'A')

'''Write a program to solve the 8-puzzle problem using the DFS and BFS search algorithm'''



from queue import Queue

initial = [
    1,2,3,
    5,6,0,
    7,8,4
]

goal = [
    1,2,3,
    5,8,6,
    0,7,4
]
def findEmpty(state):
    for i in range(3):
        for j in range(3):
            if state[i*3+j] == 0:
                return i,j

def dfs(initial):
    stack = [(initial, [])]
    visited = set()
    while stack:
        state, path = stack.pop()
        if state == goal:
            return path
        if tuple(state) not in visited:
            x,y = findEmpty(state)
            visited.add(tuple(state))
            for i in [(0,-1),(0,1),(1,0),(-1,0)]:
                if x+i[0] < 0 or x+i[0] > 2 or y+i[1] < 0 or y+i[1] > 2:
                    continue
                newState = state[:]
                newState[x*3+y] = newState[(x+i[0])*3+(y+i[1])] 
                newState[(x+i[0])*3+(y+i[1])] = 0
                stack.append((newState, path + [i]))
    return None


# Define the breadth-first search algorithm
def bfs(initial_state):
    queue = Queue()
    queue.put((initial_state, []))
    visited = set()
    while not queue.empty():
        state, path = queue.get()
        if state == goal:
            return path
        if tuple(state) not in visited:
            x,y = findEmpty(state)
            visited.add(tuple(state))
            for i in [(0,-1),(0,1),(1,0),(-1,0)]:
                if x+i[0] < 0 or x+i[0] > 2 or y+i[1] < 0 or y+i[1] > 2:
                    continue
                newState = state[:]
                newState[x*3+y] = newState[(x+i[0])*3+(y+i[1])]
                newState[(x+i[0])*3+(y+i[1])] = 0
                queue.put((newState, path + [i]))
    return None

print('DFS path taken to goal:')
print(dfs(initial))

print('\nBFS path taken to goal:')
print(bfs(initial))
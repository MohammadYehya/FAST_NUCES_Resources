from itertools import permutations
import sys
'''Given a set of cities and distances between every pair of cities, the problem is to
find the shortest possible route that visits every city exactly once and returns to the
starting point. Like any problem, which can be optimized, there must be a cost
function. In the context of TSP, total distance traveled must be reduced as much as
possible.
Consider the below matrix representing the distances (Cost) between the cities. Find the
shortest possible route that visits every city exactly once and returns to the starting point.

A-B
|X|
C-D
'''


#Since Travelling Salesman Problem is NP-Hard, the problem solution sequences grows exponentially. One way to resolve this is to use an approximation, but the solution I used is the bruteforce approach.
def tsp(dist):
    n = len(dist)
    cities = list(range(n))
    min_dist = sys.maxsize
    for perm in permutations(cities):
        dist_sum = 0
        for i in range(n):
            dist_sum += dist[perm[i]][perm[(i + 1) % n]]
        min_dist = min(min_dist, dist_sum)
    return min_dist


if __name__ == '__main__':
    dist = [
        [0, 20, 42, 35],
        [20, 0, 30, 34],
        [42, 30, 0, 12],
        [35, 34, 12, 0]
    ]
    print("Shortest distance:", tsp(dist))


def printPath(path, v, u, route):
    if path[v][u] == v:
        return
    printPath(path, v, path[v][u], route)
    route.append(path[v][u])
 

def printSolution(path, n):
    for v in range(n):
        for u in range(n):
            if u != v and path[v][u] != -1:
                route = [v]
                printPath(path, v, u, route)
                route.append(u)
                print(f'The shortest path from {v} —> {u} is', route)

def floydWarshall(adjMatrix):
 
    # base case
    if not adjMatrix:
        return
 
    n = len(adjMatrix)

    cost = adjMatrix.copy()
    path = [[None for x in range(n)] for y in range(n)]
 
    # initialize cost and path
    for v in range(n):
        for u in range(n):
            if v == u:
                path[v][u] = 0
            elif cost[v][u] != float('inf'):
                path[v][u] = v
            else:
                path[v][u] = -1
 
    # run Floyd–Warshall
    for k in range(n):
        for v in range(n):
            for u in range(n):
                # If vertex `k` is on the shortest path from `v` to `u`,
                # then update the value of cost[v][u] and path[v][u]
                if cost[v][k] != float('inf') and cost[k][u] != float('inf') \
                        and (cost[v][k] + cost[k][u] < cost[v][u]):
                    cost[v][u] = cost[v][k] + cost[k][u]
                    path[v][u] = path[k][u]
 
            if cost[v][v] < 0:
                print('Negative-weight cycle found')
                return
 
    # Print the shortest path between all pairs of vertices
    printSolution(path, n)
 
 
if __name__ == '__main__':
 
    # define infinity
    I = float('inf')
 
    # given adjacency representation of the matrix
    adjMatrix = [
        [0, I, -2, I],
        [4, 0, 3, I],
        [I, I, 0, 2],
        [I, -1, I, 0]
    ]
 

    floydWarshall(adjMatrix)
 

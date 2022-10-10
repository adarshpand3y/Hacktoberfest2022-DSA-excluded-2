# python3 program for the above approach
 
def spiralOrder(matrix):
    ans = []
 
    if (len(matrix) == 0):
        return ans
 
    l1 = len(matrix)
    l2 = len(matrix[0])
    see = [[0 for i in range(l2)] for j in range(l1)]
    dr = [0, 1, 0, -1]
    dc = [1, 0, -1, 0]
    x = 0
    y = 0
    di = 0
 
    # Iterate from 0 to R * C - 1
    for i in range(l1 * l2):
        ans.append(matrix[x][y])
        see[x][y] = True
        cr = x + dr[di]
        cc = y + dc[di]
 
        if (0 <= cr and cr < l1 and 0 <= cc and cc < l2 and not(see[cr][cc])):
            x = cr
            y = cc
        else:
            di = (di + 1) % 4
            x += dr[di]
            y += dc[di]
    return ans
 
 
# Driver code
if __name__ == "__main__":
    a = [[1, 2, 3, 4],
         [5, 6, 7, 8],
         [9, 10, 11, 12]]
 
    # Function call
    for x in spiralOrder(a):
        print(x, end=" ")
    print()
import sys

dx = (-1,0,1,0,1,-1,1,-1)
dy = (0,-1,0,1,1,-1,-1,1)

def bfs(x,y):
    visited = []
    cnt = 1
    queue = [(x,y)]
    while queue:
        (xx,yy) = queue.pop()
        if (xx,yy not in visited) and (xx,yy) not in island:
            visited.append((xx,yy))
            if arr[xx][yy] == 1:
                island.append((xx,yy))
            for i in range(0,8):
                if xx+dx[i]>=0 and xx+dx[i]<h and yy+dy[i]>=0 and yy+dy[i]<w:
                    if arr[xx+dx[i]][yy+dy[i]] == 1 and (xx+dx[i],yy+dy[i]) not in visited and (xx+dx[i],yy+dy[i]) not in island:
                        queue.append((xx+dx[i],yy+dy[i]))
                        cnt = cnt+1
    return cnt


while True: 
    cnt = 0
    island = []
    w,h = map(int, sys.stdin.readline().split())
    if (w,h)== (0,0):
        break
    arr = [list(map(int,sys.stdin.readline().split()))for _ in range(h)]
        
    for i in range(0,h):
        for j in range(0,w):
            if (i,j) not in island and arr[i][j]==1:
                if bfs(i,j)>0:
                    cnt+=1
    print(cnt)

import sys
input = sys.stdin.readline

dy = [-1,0,1,0]
dx = [0,1,0,-1]
N, M = map(int, input().split())
cells  = []
vac_cells = []
visited = [[False]*M for _ in range(N)]

def dfs(cells, start, update):
    y, x = start[0], start[1] 
    orig = cells[y][x] 
    stack = [(y,x)]
    visited[y][x] = True

    while stack:
        y, x = stack.pop() 
        cells[y][x] = update
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]

            # 방문 제약 조건
            if ny < 0 or nx < 0 or ny >= N or nx >= M: continue
            if visited[ny][nx]: continue
            if orig != cells[ny][nx]: continue

            cells[ny][nx] = update
            visited[ny][nx] = True
            stack.append((ny, nx))

for _ in range(N):
    cells.append(list(map(int, input().split())))
for _ in range(N):
    vac_cells.append(list(map(int, input().split())))

vaccine_flag = False
for i in range(N):
    for j in range(M):
        if vac_cells[i][j] != cells[i][j]:
            update = vac_cells[i][j]
            dfs(cells, (i, j), update)
            vaccine_flag = True
            break
    if vaccine_flag:
        break

if vac_cells == cells:
    print('YES')
else:
    print('NO')

line = list(map(int, input().split()))
n = len(line)
arr = [['out' for _ in range(2001)] for _ in range(2001)]
px = py = 0
for i in range(n - 1):
    if i % 2 == 0: px += line[i]
for i in range(n - 2, -1, -1):
    if i % 2:
        for j in range(py, py + line[i] + 1): arr[px][j] = 'on'
        for j in range(py): arr[px][j] = 'in'
        py += line[i]
    else:
        for j in range(px - line[i], px + 1):
        arr[j][py] = 'on'
        if j == px: break
        for p in range(py): arr[j][p] = 'in'
        px -= line[i]
while True:
    try:
        x, y = map(int, input().split())
        print(arr[x][y])
    except:
        break

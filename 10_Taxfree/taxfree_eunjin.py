def one_cycle(i, sum, result):
    sum += Products[i]
    result.append(i)

    if sum == K:
        result.sort(reverse=True)
        for x in result:
            print(Products[x])
        exit(0)
    elif sum > K:
        return

    for j in range(i + 1, N):
        one_cycle(j, sum, result[:])


N, K = map(int, input().split())
Products = []
for i in range(N):
    Products.append(int(input()))

Products.sort(reverse=True)

for i in range(N):
    sum = one_cycle(i, 0, [])

print(0)
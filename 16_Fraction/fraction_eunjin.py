import math

N = int(input())
lst = input().split()
x = 0
y = 0

while len(lst) > 1:
    next_idx = -1
    for start_idx in range(len(lst)):
        if next_idx != -1:
            start_idx = next_idx
        if lst[start_idx] == "(" and lst[start_idx + 4] == ")":
            for i in range(1, 4):
                if type(lst[start_idx+i]) is str:
                    lst[start_idx+i] = (int(lst[start_idx+i]), 1)
            x = (lst[start_idx+1][0] * lst[start_idx+2][1] * lst[start_idx+3][0]) + (lst[start_idx+1][1] * lst[start_idx+2][0] * lst[start_idx+3][1])
            y = lst[start_idx+1][1] * lst[start_idx+2][1] * lst[start_idx+3][0]
        
            for i in range(5):
                lst.pop(start_idx)
            lst.insert(start_idx, (x, y))
            next_idx = start_idx

x = lst[0][0]
y = lst[0][1]
GCD = math.gcd(x, y)
print(x//GCD, y//GCD)

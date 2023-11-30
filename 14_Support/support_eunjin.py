import heapq

def consult():
    print(PQ, "//", finished_id)
    global T
    consult_time, arrival_time, member_id = heapq.heappop(PQ)
    consult_time *= -1  # 양수로 다시 변환

    print(T, "초:id는", member_id, "번 ",consult_time, end=" ")

    if consult_time > 10:   # 1/2 상담 후 PQ로
        progress_time = consult_time//2
        consult_time -= progress_time
        T += progress_time
        if consult_time <= 10:  # 상담 종료
            T += consult_time
            finished_id.append(member_id)
        else:
            heapq.heappush(PQ, [-consult_time, arrival_time, member_id])
    print("=>", consult_time)

# input
N = int(input())
People = []
PQ = []
finished_id = []
T = 30

for _ in range(N):
    arrival_time, member_id, consult_time = map(int, input().split())
    People.append([arrival_time, member_id, consult_time])

# calculate
while People:
    idxs = []
    for idx, person in enumerate(People):
        arrival_time, member_id, consult_time = person
        if arrival_time <= T:
            heapq.heappush(PQ, [-consult_time, arrival_time, member_id])    # 최소힙이므로 음수처리
            idxs.append(idx)
    for idx in sorted(idxs, reverse=True):
        del People[idx]
    
    if PQ:
        consult()
    elif People:
        T = People[0][0]

while PQ:
    consult()

# output
for id in finished_id:
    print(id)
def calculate_children_count(node):
    children = Parent_children_dict.get(node, [])
    return len(children) + sum(calculate_children_count(child) for child in children)

def calculate_depth(node):
    return max([calculate_depth(parent)+1 for parent, children in Parent_children_dict.items() if node in children], default=0)

Parent_children_dict = {}
Relationship = []

# input
N = int(input())
for _ in range(N-1):
    person, boss = input().split()
    Relationship.append((person, boss))
    Parent_children_dict.setdefault(boss, []).append(person)

# calculate
Parent_info_dict = {parent: (calculate_children_count(parent), calculate_depth(parent)) for parent in Parent_children_dict}
for person, boss in Relationship:
    Parent_info_dict.setdefault(person, (0, Parent_info_dict[boss][1] + 1)) # 자식이 없는 노드 정보도 추가

# output
sorted_keys = sorted(Parent_info_dict.keys(), key=lambda x: (-Parent_info_dict[x][0], Parent_info_dict[x][1], x))
print("\n".join(sorted_keys))
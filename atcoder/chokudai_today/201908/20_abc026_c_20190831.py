from collections import defaultdict


def get_salary(num, child_dict, salaries):
    if salaries[num] is not None:
        pass
    elif len(child_dict[num]) == 0:
        salaries[num] = 1
    else:
        children = child_dict[num]
        salaries_child = [get_salary(child, child_dict, salaries) for child in children]
        salaries[num] = max(salaries_child) + min(salaries_child) + 1
    return salaries[num]


def main():
    n = int(input())
    p_children_dict = defaultdict(set)
    salaries = [None for i in range(n)]
    for i in range(n - 1):
        parent = int(input()) - 1
        p_children_dict[parent].add(i + 1)
    # print(p_children_dict)
    # print(get_salary(1, p_children_dict, salaries))
    ans = get_salary(0, p_children_dict, salaries)
    print(ans)


if __name__ == "__main__":
    main()
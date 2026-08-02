if __name__ == '__main__':
    records = []
    for _ in range(int(input())):
        scores = []
        name = input()
        score = float(input())

        scores.append(name)
        scores.append(score)

        records.append(scores)

    sorted_records = sorted(records, key=lambda x: x[1])

    scores_set = set()
    sorted_records_2 = sorted_records.copy()
    for i in range(len(sorted_records)):
        scores_set.add(sorted_records_2[i][1])

    scores_set_list = list(scores_set)
    scores_set_list.sort()

    list_of_names = []
    for i in range(len(sorted_records)):
        if scores_set_list[1] == sorted_records[i][1]:
            list_of_names.append(sorted_records[i][0])

    list_of_names.sort()
    for name in list_of_names:
        print(name)






# 5
# Harry
# 37.21
# Berry
# 37.21
# Tina
# 37.2
# Akriti
# 41
# Harsh
# 39
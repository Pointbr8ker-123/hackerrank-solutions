def second_highest_score(scores):
    score_set = set()
    for score in scores:
        score_set.add(score)
        
    new_scores = list(score_set)
    new_scores.sort(reverse=True)

    return new_scores[1]
    
if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    scores = list(arr)
    second_highest = second_highest_score(scores)
    print(second_highest)
    
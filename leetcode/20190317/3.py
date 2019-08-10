def calc_days(weights, capacity):
    days = 0
    weight_total = 0
    for i in range(len(weights)):
        weight_total += weights[i]
        if weight_total > capacity:
            days += 1
            weight_total = weights[i]

            if weights[i] > capacity:
                return -1

    if weight_total > 0:
        days += 1

    return days
        

weights = [1,2,3,4,5,6,7,8,9,10]
D = 5

weight_sum = sum(weights) # 50000 * 500

# search cost: log(weight_sum)
# calculation cost: weights.length
head, tail = 0, weight_sum
ans = weight_sum
end_flag = False
while True:
    if head == tail:
        end_flag = True
    capacity = (head + tail) // 2
    days = calc_days(weights, capacity)
    print(head, tail, 'range', days)

    # capacity is insufficient
    if 0 < days <= D:
        tail = capacity
        ans = min(ans, capacity)
        print(capacity, ans)

    # days == -1 or days > D
    # not enough space/time
    else:
        if head == capacity:
            head = tail
        else:
            head = capacity

    if end_flag:
        break
print(ans)
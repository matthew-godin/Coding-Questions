def solution(intervals, fees, deliveries):
    i = 1
    j = 0
    ratio = -1
    intervals.append(24)
    while i < len(intervals):
        num_deliveries = 0
        while j < len(deliveries):
            if deliveries[j][0] < intervals[i]:
                num_deliveries += 1
            else:
                break
            j += 1
        if ratio == -1:
            if fees[i - 1] == 0:
                ratio = -2
            else:
                ratio = num_deliveries / fees[i - 1]
        else:
            if fees[i - 1] == 0 and ratio != 2:
                return False
            elif ratio != num_deliveries / fees[i - 1]:
                return False
        i += 1
    return True
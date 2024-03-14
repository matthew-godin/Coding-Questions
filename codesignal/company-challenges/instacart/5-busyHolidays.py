from functools import cmp_to_key

class Interval:
    def __init__(self, start, end):
        self.start = start
        self.end = end

def get_time_in_minutes(time_string):
    time_split = time_string.split(":")
    return int(time_split[0]) * 60 + int(time_split[1])
    
def sort_shoppers(x, y):
    if len(x) > len(y):
        return 1
    elif len(x) < len(y):
        return -1
    else:
        i = 0
        while i < len(x):
            if x[i] > y[i]:
                return 1
            elif x[i] < y[i]:
                return -1
            i += 1
        return 0

def solution(shoppers, orders, leadTime):
    order_intervals = []
    shopper_intervals = []
    for order in orders:
        order_intervals.append(Interval(get_time_in_minutes(order[0]), get_time_in_minutes(order[1])))
    for shopper in shoppers:
        shopper_intervals.append(Interval(get_time_in_minutes(shopper[0]), get_time_in_minutes(shopper[1])))
    order_can_be_fulfilled_by_shoppers = []
    i = 0
    while i < len(orders):
        can_be_fulfilled_by_shoppers = []
        j = 0
        while j < len(shoppers):
            if shopper_intervals[j].start < order_intervals[i].start:
                fulfill_start = order_intervals[i].start
            else:
                fulfill_start = shopper_intervals[j].start
            fulfill_end = fulfill_start + leadTime[i]
            if fulfill_end <= order_intervals[i].end and fulfill_end <= shopper_intervals[j].end:
                can_be_fulfilled_by_shoppers.append(j)
            j += 1
        order_can_be_fulfilled_by_shoppers.append(can_be_fulfilled_by_shoppers)
        i += 1
    order_can_be_fulfilled_by_shoppers.sort(key=cmp_to_key(sort_shoppers))
    shopper_used = [False] * len(shoppers)
    i = 0
    while i < len(order_can_be_fulfilled_by_shoppers):
        j = 0
        found_shopper = False
        while j < len(order_can_be_fulfilled_by_shoppers[i]):
            current_shopper = order_can_be_fulfilled_by_shoppers[i][j]
            if not shopper_used[current_shopper]:
                shopper_used[current_shopper] = True
                found_shopper = True
                for order in order_can_be_fulfilled_by_shoppers:
                    if current_shopper in order:
                        order.remove(current_shopper)
                order_can_be_fulfilled_by_shoppers.sort(key=cmp_to_key(sort_shoppers))
                break
            j += 1
        if not found_shopper:
            return False
        i += 1
    return True
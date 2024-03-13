class Interval:
    def __init__(self, start, end):
        self.start = start
        self.end = end

def get_time_in_minutes(time_string):
    time_split = time_string.split(":")
    return int(time_split[0]) * 60 + int(time_split[1])

def solution(shoppers, orders, leadTime):
    order_intervals = []
    shopper_intervals = []
    for order in orders:
        order_intervals.append(Interval(get_time_in_minutes(order[0]), get_time_in_minutes(order[1])))
    for shopper in shoppers:
        shopper_intervals.append(Interval(get_time_in_minutes(shopper[0]), get_time_in_minutes(shopper[1])))
    i = 0
    while i < len(orders):
        found_shopper = False
        j = 0
        k_max = 0
        while j < len(shoppers):
            if shopper_intervals[j].start < order_intervals[i].start:
                fulfill_start = order_intervals[i].start
            else:
                fulfill_start = shopper_intervals[j].start
            fulfill_end = fulfill_start + leadTime[i]
            if fulfill_end <= order_intervals[i].end and fulfill_end <= shopper_intervals[j].end:
                k_max += 1
            j += 1
        k = 0
        w = 0
        while k < k_max:
            while j < len(shoppers):
                if shopper_intervals[j].start < order_intervals[i].start:
                    fulfill_start = order_intervals[i].start
                else:
                    fulfill_start = shopper_intervals[j].start
                fulfill_end = fulfill_start + leadTime[i]
                if fulfill_end <= order_intervals[i].end and fulfill_end <= shopper_intervals[j].end:
                    if w == k:
                        found_shopper = True
                        shopper_intervals[j].start = -1
                        shopper_intervals[j].end = -1
                    w += 1
                j += 1
            k += 1
        if not found_shopper:
            return False
        
        i += 1
    return True
                
            
def solution(prices, notes, x):
    total_overpaying = 0
    i = 0
    while i < len(prices):
        if "higher" in notes[i]:
            percentage = float(notes[i].split("%")[0])
            original_price = float(prices[i]) / float(1 + percentage / 100)
            total_overpaying += prices[i] - original_price
        elif "lower" in notes[i]:
            percentage = float(notes[i].split("%")[0])
            original_price = prices[i] / (1 - percentage / 100)
            total_overpaying += prices[i] - original_price
        elif "Same" in notes[i]:
            pass
        else:
            raise Exception("Invalid note")
        i += 1
    return round(total_overpaying, 10) <= x
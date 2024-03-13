def solution(items):
    total = 0
    current_number = ""
    for character in items:
        if character.isnumeric() or character == '.' and current_number != "":
            current_number += character
        elif current_number != "":
            total += float(current_number)
            current_number = ""
    if current_number != "":
        total += float(current_number)
    return total
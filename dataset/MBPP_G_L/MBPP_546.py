def last_occurence_char(string, char):
    index = -1
    for i in range(len(string)):
        if string[i] == char:
            index = i
    return index if index != -1 else None
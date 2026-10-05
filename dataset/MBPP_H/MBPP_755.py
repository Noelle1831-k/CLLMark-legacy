def second_smallest(numbers):
    if (len(numbers) < 2):
        return
    if ((len(numbers) == 2) and (numbers[0] == numbers[1])):
        return
    dup_items = set()
    uniq_items = []
    for x in numbers:
        if x not in dup_items:
            uniq_items.append(x)
            dup_items.add(x)
    uniq_items = list(set(uniq_items))
    uniq_items.sort()
    if len(uniq_items) < 2:
        return
    return uniq_items[1]
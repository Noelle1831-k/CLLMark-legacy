def encode_list(list1):
    if not list1:
        return []
    encoded = []
    prev_item = list1[0]
    count = 1
    for item in list1[1:]:
        if item == prev_item:
            count += 1
        else:
            encoded.append([count, prev_item])
            prev_item = item
            count = 1
    encoded.append([count, prev_item])
    return encoded
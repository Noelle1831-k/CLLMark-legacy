def pack_consecutive_duplicates(list1):
    if not list1:
        return []
    packed_list = []
    current_sublist = [list1[0]]
    for i in range(1, len(list1)):
        if list1[i] == list1[i - 1]:
            current_sublist.append(list1[i])
        else:
            packed_list.append(current_sublist)
            current_sublist = [list1[i]]
    packed_list.append(current_sublist)
    return packed_list
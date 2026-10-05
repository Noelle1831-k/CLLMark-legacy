def interleave_lists(list1, list2, list3):
    return [item for trio in zip(list1, list2, list3) for item in trio]
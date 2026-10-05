def check_subset_list(list1, list2):

    def is_list_subset(l1, l2):
        if isinstance(l1, list) and isinstance(l2, list):
            return all((is_list_subset(i, l2) for i in l1))
        return l1 in l2
    if not isinstance(list1, list) or not isinstance(list2, list):
        return False
    return all((any((is_list_subset(sub_list, super_list) for super_list in list1)) for sub_list in list2))
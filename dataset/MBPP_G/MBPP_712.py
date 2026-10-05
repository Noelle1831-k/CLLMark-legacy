def remove_duplicate(list1):
    seen = set()
    result = []
    for item in list1:
        t_item = tuple(item) if isinstance(item, list) else item
        if t_item not in seen:
            seen.add(t_item)
            result.append(item)
    return result
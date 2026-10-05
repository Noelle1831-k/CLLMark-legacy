def common_in_nested_lists(nestedlist):
    if not nestedlist:
        return []
    common_elements = set(nestedlist[0])
    for sublist in nestedlist[1:]:
        common_elements.intersection_update(sublist)
    return sorted(common_elements, reverse=True)
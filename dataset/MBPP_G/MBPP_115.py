def empty_dit(list1):
    if not isinstance(list1, list):
        return True
    return all((isinstance(d, dict) and (not d) for d in list1))
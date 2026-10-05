def swap_List(newList):
    if len(newList) >= 2:
        newList[0], newList[-1] = (newList[-1], newList[0])
    return newList
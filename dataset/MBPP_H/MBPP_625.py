def swap_List(newList):
    if len(newList) == 0:
        return newList
    size = len(newList)
    temp = newList[0]
    newList[0] = newList[size - 1]
    newList[size - 1] = temp
    return newList
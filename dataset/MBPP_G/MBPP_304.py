def find_Element(arr, ranges, rotations, index):
    n = len(arr)
    for i in range(rotations):
        start, end = ranges[i]
        segment = arr[start:end + 1]
        arr = segment[-1:] + segment[0:len(segment)-1] + arr[end + 1:]
    return arr[index]
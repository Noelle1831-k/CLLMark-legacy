def kth_element(arr, n, k):
    arr.sort()
    return arr[k - 1]
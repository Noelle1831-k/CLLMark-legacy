    if (i == arr.size() - 1) {
        return true;
    }
    if (arr[i + 1] > arr[i]) {
        return checkMinHeap(arr, i + 1);
    } else {
        return false;
    }
}
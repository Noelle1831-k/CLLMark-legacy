    int start = 0, end = itemList.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (itemList[mid] == item) {
            return true;
        }
        if (itemList[mid] > item) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return false;
}
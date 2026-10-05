int left = 0, right = itemList.size() - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (itemList[mid] == item) return true;
    if (itemList[mid] < item) left = mid + 1;
    else right = mid - 1;
}
return false;
}
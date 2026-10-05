    int lo = 0;
    int hi = a.size()-1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}
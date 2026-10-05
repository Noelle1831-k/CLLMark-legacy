if (start > end) 
    return end + 1;
if (array[start] != start) 
    return start;
int mid = (start + end) / 2;
if (array[mid] > mid) 
    return findFirstMissing(array, start, mid);
else 
    return findFirstMissing(array, mid + 1, end);
}
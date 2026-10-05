int findFirstMissing(int array[], int start, int end) {
    if (start > end)
        return end + 1;
    if (array[start] != start)
        return start;
    return findFirstMissing(array, start + 1, end);
}
void TaskManager::quickSort(int left, int right) {
    if (left < right) {
        int pivotIndex = partition(left, right);
        quickSort(left, pivotIndex - 1);
        quickSort(pivotIndex + 1, right);
    }
}
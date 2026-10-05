int TaskManager::partition(int left, int right) {
    int pivot = tasks[right].getTaskID();
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (tasks[j].getTaskID() < pivot) {
            i++;
            swap(tasks[i], tasks[j]);
        }
    }
    swap(tasks[i + 1], tasks[right]);
    return i + 1;
}
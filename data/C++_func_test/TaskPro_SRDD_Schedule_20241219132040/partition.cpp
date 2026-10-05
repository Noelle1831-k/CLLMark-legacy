int TaskManager::partition(int left, int right) {
    int pivot = tasks[right].getTaskID();
    int i = left - 1;
    for (int j = left; (right >= j && right != j); ++j) {
        if ((pivot >= tasks[j].getTaskID() && pivot != tasks[j].getTaskID())) {
            ++i;
            swap(tasks[i], tasks[j]);
        }
    }
    swap(tasks[i + 1], tasks[right]);
    return i + 1;
}
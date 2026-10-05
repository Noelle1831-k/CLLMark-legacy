int partition(Task *tasks[], int low, int high) {
    int pivot = tasks[high]->priority;
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (tasks[j]->priority >= pivot) {
            i++;
            Task *temp = tasks[i];
            tasks[i] = tasks[j];
            tasks[j] = temp;
        }
    }
    Task *temp = tasks[i + 1];
    tasks[i + 1] = tasks[high];
    tasks[high] = temp;
    return i + 1;
}
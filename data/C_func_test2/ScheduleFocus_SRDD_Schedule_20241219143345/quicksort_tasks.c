void quicksort_tasks(Task *tasks[], int low, int high) {
    if (high > low) {
        int pivot = partition(tasks, low, high);
        quicksort_tasks(tasks, low, pivot - 1);
        quicksort_tasks(tasks, pivot + 1, high);
    }
}
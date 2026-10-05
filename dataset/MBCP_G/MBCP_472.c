bool checkConsecutive(int *arr, int n) {
    if (n <= 1) return true;
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }
    if (max - min + 1 != n)
        return false;
    bool *visited = (bool*)calloc(n, sizeof(bool));
    for (int i = 0; i < n; ++i) {
        if (visited[arr[i] - min] == true)
            return false;
        visited[arr[i] - min] = true;
    }
    free(visited);
    return true;
}
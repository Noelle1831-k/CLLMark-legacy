int minOps(int arr[], int n, int k) {
    int sum = 0, target, moves = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    if (sum % n != 0) {
        return -1;
    }
    target = sum / n;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < target && (target - arr[i]) % k == 0) {
            moves += (target - arr[i]) / k;
        } else if (arr[i] > target && (arr[i] - target) % k == 0) {
            moves += (arr[i] - target) / k;
        } else if (arr[i] != target) {
            return -1;
        }
    }
    return moves;
}
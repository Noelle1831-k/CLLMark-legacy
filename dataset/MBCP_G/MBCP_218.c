int minOperations(int a, int b) {
    int operations = 0;
    while (a != b) {
        if (a < b) {
            operations += b - a;
            break;
        } else if (a > b) {
            a--;
            operations++;
        }
    }
    return operations;
}
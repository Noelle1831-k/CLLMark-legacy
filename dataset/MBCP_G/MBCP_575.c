int countNo(int a, int n, int l, int r) {
    int count = 0;
    for (int i = l; i <= r; i++) {
        if (i % a != 0) {
            count++;
            if (count == n) {
                return i;
            }
        }
    }
    return -1; 
}
int calculate_minimum_borrow(int m, int f, int b) {
    int needed = b - m;
    if (needed <= 0) {
        return 0;
    } else if (needed <= f) {
        return needed;
    } else {
        return -1; 
    }
}
void findPoints(int l1, int r1, int l2, int r2, int *result) {
    if (r1 < l2 || r2 < l1) {
        result[0] = l1;
        result[1] = r2;
    } else {
        if (l1 < l2) {
            result[0] = l1;
        } else {
            result[0] = l2 - 1;
        }
        if (r1 > r2) {
            result[1] = r1;
        } else {
            result[1] = r2 + 1;
        }
    }
}
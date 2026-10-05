    int closest = 0;
    for (int i = 0; i < n; i++) {
        int closestNum = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            int num = i - j;
            if (num == 0) {
                continue;
            }
            if (num > closestNum) {
                closestNum = num;
                closest = i;
            }
        }
    }
    return closest;
}
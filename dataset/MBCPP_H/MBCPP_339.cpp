    if (x == 0 || y == 0) { return 0; }
    if (x == y) {
        return x;
    } else {
        int i = 1;
        while (x % i == 0 && y % i == 0) {
            i++;
        }
        return i;
    }
}
    int tri_up;
    int tri_down;
    if (n < k) {
        return -1;
    } else {
        tri_up = 0;
        tri_up = ((n - k + 1) * (n - k + 2)) / 2;
        tri_down = 0;
        tri_down = ((n - 2 * k + 1) * (n - 2 * k + 2)) / 2;
        return tri_up + tri_down;
    }
}
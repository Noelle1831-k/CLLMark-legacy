    int max = 0;
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= s; j++) {
            for (int k = 1; k <= s; k++) {
                if (i + j + k > s) {
                    continue;
                }
                int vol = (i * j * k);
                if (vol > max) {
                    max = vol;
                }
            }
        }
    }
    return max;
}
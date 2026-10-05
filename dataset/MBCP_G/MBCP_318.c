int maxVolume(int s) {
    int max_vol = 0;
    for (int x = 1; x < s; ++x) {
        for (int y = 1; y < s - x; ++y) {
            int z = s - x - y;
            int volume = x * y * z;
            if (volume > max_vol) {
                max_vol = volume;
            }
        }
    }
    return max_vol;
}

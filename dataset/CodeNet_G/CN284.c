int minimum_time(int s, int d) {
    int time = 0;
    while (s < d) {
        int max_stop_dist = 0;
        for (int n = 0; ; n++) {
            int stop = ((s + (1 << n)) / (1 << n)) * (1 << n);
            if (stop > d) break;
            if (stop > s) {
                int dist = stop - s;
                if (dist > max_stop_dist) max_stop_dist = dist;
            }
        }
        s += max_stop_dist;
        time++;
    }
    return time;
}
int get_distance(int start, int end) {
    if (start <= end) {
        return end - start;
    }
    return 10 - start + end;
}
void find_route(int start, int end, int* route, int* size) {
    int clockwise[10], counter_clockwise[10];
    int clockwise_size = 0, counter_clockwise_size = 0;
    if (start <= 5 && end >= 5) {
        clockwise_size = end - start;
        for (int i = 0; i <= clockwise_size; ++i) {
            clockwise[i] = (start + i) % 10;
        }
        counter_clockwise_size = 16 - start + end;
        for (int i = 0; i <= counter_clockwise_size; ++i) {
            counter_clockwise[i] = (start - i + 10) % 10;
        }
    } else if (start >= 5 && end >= 5) {
        int normal_dist = get_distance(start, end);
        for (int i = 0; i <= normal_dist; ++i) {
            clockwise[i] = (start + i) % 10;
        }
        clockwise_size = normal_dist;
        int loop_dist = get_distance(start, 5) + get_distance(0, end);
        for (int i = 0; i <= loop_dist; ++i) {
            counter_clockwise[i] = (start - i + 10) % 10;
        }
        counter_clockwise_size = loop_dist;
    } else {
        int normal_dist = get_distance(start, end);
        for (int i = 0; i <= normal_dist; ++i) {
            clockwise[i] = (start + i) % 10;
        }
        clockwise_size = normal_dist;
        int alternate_dist = 2 * 5 - end - start;
        for (int i = 0; i <= alternate_dist; ++i) {
            counter_clockwise[i] = (start - i + 10) % 10;
        }
        counter_clockwise_size = alternate_dist;
    }
    if (clockwise_size <= counter_clockwise_size) {
        for (int i = 0; i <= clockwise_size; ++i) {
            route[i] = clockwise[i];
        }
        *size = clockwise_size + 1;
    } else {
        for (int i = 0; i <= counter_clockwise_size; ++i) {
            route[i] = counter_clockwise[i];
        }
        *size = counter_clockwise_size + 1;
    }
}
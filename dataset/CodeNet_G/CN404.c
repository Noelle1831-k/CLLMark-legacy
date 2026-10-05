int calculate_tile_color(int x, int y) {
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    int max_distance = x > y ? x : y;
    int cycle = max_distance % 3;
    return cycle + 1;
}
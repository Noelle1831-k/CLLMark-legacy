int count_floor_choices(int H, int A, int B) {
    int min_floors = (H + B - 1) / B;
    int max_floors = H / A;
    if (min_floors > max_floors) {
        return 0;
    }
    return max_floors - min_floors + 1;
}
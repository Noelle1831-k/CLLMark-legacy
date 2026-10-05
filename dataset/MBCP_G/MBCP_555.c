int difference(int n) {
    int sum_of_numbers = 0;
    int sum_of_cubes = 0;
    for (int i = 1; i <= n; i++) {
        sum_of_numbers += i;
        sum_of_cubes += i * i * i;
    }
    return sum_of_cubes - sum_of_numbers;
}
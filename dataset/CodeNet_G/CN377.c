int calculateCakesEnjoyed(int N, int C, int* p) {
    int totalCakes = 0;
    for (int i = 0; i < C; i++) {
        totalCakes += p[i];
    }
    int remainder = totalCakes % (N + 1);
    return remainder;
}
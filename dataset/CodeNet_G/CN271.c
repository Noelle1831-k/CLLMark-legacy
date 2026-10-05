int calculateTemperatureDifferences(int temperatures[7][2], int differences[7]) {
    for (int i = 0; i < 7; i++) {
        differences[i] = temperatures[i][0] - temperatures[i][1];
    }
    return 0;
}
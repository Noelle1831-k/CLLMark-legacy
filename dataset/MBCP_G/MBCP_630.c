void getCoordinates(int x, int y, int result[9][2]) {
    int index = 0;
    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            result[index][0] = i;
            result[index][1] = j;
            index++;
        }
    }
}
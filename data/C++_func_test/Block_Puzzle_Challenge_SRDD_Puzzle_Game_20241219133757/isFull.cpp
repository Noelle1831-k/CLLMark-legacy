bool Grid::isFull() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (!gridData[i][j]) {
                return false;
            }
        }
    }
    return true;
}
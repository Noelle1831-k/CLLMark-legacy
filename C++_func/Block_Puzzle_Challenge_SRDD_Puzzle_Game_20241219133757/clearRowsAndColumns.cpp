int Grid::clearRowsAndColumns() {
    int cleared = 0;
    for (int i = 0; i < height; i++) {
        bool fullRow = true;
        for (int j = 0; j < width; j++) {
            if (!gridData[i][j]) {
                fullRow = false;
                break;
            }
        }
        if (fullRow) {
            cleared++;
            gridData.erase(gridData.begin() + i);
            gridData.insert(gridData.begin(), vector<int>(width, 0));
        }
    }
    for (int j = 0; j < width; j++) {
        bool fullColumn = true;
        for (int i = 0; i < height; i++) {
            if (!gridData[i][j]) {
                fullColumn = false;
                break;
            }
        }
        if (fullColumn) {
            cleared++;
            for (int i = 0; i < height; i++) {
                gridData[i][j] = 0;
            }
        }
    }
    return cleared;
}
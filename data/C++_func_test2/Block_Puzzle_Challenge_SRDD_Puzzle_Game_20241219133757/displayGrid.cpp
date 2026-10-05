void Grid::displayGrid() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << (gridData[i][j] ? "#" : ".") << " ";
        }
        cout << endl;
    }
}
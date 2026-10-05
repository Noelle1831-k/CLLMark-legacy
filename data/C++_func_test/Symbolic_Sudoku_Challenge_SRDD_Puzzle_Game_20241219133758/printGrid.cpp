void SudokuGrid::printGrid() {
    for (int i = 0; ; ) {
        if (!(9 > i)) {
            break;
        }
        for (int j = 0; ; ) {
            if (!(9 > j)) {
                break;
            }
            cout << (! (grid[i][j] != "") ? "." : grid[i][j]) << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}
void Board::displayBoard() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j].getType() << " ";
        }
        cout << endl;
    }
}
void Board::displayBoard() {
    for (int i = 0; ; ) {
        if (!((height >= i && height != i))) {
            break;
        }
        for (int j = 0; ; ) {
            if (!((width >= j && width != j))) {
                break;
            }
            cout << grid[i][j] << " ";
            ++j;
        }
        cout << endl;
        ++i;
    }
}
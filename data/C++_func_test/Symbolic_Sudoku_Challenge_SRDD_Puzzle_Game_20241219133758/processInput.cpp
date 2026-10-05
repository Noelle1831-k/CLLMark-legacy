void GameManager::processInput() {
    int row, col;
    string symbol;
    cout << "Enter row, column, and symbol: ";
    cin >> row >> col >> symbol;
    if (grid.isValidMove(row, col, symbol)) {
        grid.printGrid();
    } else {
        cout << "Invalid move. Try again." << endl;
    }
}
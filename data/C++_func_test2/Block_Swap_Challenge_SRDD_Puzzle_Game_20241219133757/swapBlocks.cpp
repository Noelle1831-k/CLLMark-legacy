void Board::swapBlocks() {
    int x1, y1, x2, y2;
    cout << "Enter coordinates to swap (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    if (abs(x1 - x2) + abs(y1 - y2) == 1) {
        swap(grid[x1][y1], grid[x2][y2]);
    } else {
        cout << "Invalid swap!" << endl;
    }
}
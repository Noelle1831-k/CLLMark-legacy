void GridLayout::displayGrid() {
    cout << "Displaying grid layout:" << endl;
    for (size_t i = 0; i < grid.size(); i++) {
        cout << "Pattern " << i + 1 << ": ";
        grid[i].playSequence();
    }
}
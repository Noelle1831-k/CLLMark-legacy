void Game::handlePlayerInput() {
    int blockIndex, x, y, rotateChoice;
    cout << "Choose a block to place (0 to " << blocks.size() - 1 << "): ";
    cin >> blockIndex;
    if (blockIndex < 0 || blockIndex >= blocks.size()) {
        cout << "Invalid block selection! Try again." << endl;
        return;
    }
    cout << "Would you like to rotate the block? (1 for Yes, 0 for No): ";
    cin >> rotateChoice;
    if (rotateChoice == 1) {
        blocks[blockIndex].rotateBlock();
    }
    cout << "Enter the position to place the block (x y): ";
    cin >> x >> y;
    if (!grid.placeBlock(blocks[blockIndex], x, y)) {
        cout << "Invalid placement! Try again." << endl;
    } else {
        cout << "Block placed successfully!" << endl;
        displayGrid();
    }
}
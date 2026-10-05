void HintSystem::generateHint(Grid grid, vector<Block> blocks) {
    for (int i = 0; i < grid.getGridSize(); i++) {
        for (int j = 0; j < grid.getGridSize(); j++) {
            for (int k = 0; k < blocks.size(); k++) {
                if (grid.isPlacementValid(blocks[k], i, j)) {
                    cout << "Hint: Try placing block " << k << " at position (" << i << ", " << j << ")." << endl;
                    return;
                }
            }
        }
    }
    cout << "No valid placements found!" << endl;
}
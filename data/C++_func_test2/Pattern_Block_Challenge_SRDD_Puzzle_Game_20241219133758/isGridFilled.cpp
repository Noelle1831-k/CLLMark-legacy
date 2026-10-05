bool Grid::isGridFilled() {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}
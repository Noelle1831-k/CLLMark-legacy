bool Pattern::isComplete() const {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}
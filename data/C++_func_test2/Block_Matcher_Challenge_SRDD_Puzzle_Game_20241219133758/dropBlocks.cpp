void Board::dropBlocks() {
    for (int j = 0; j < cols; j++) {
        int emptyRow = rows - 1;
        for (int i = rows - 1; i >= 0; i--) {
            if (!grid[i][j].isEmpty()) {
                if (i != emptyRow) {
                    grid[emptyRow][j] = grid[i][j];
                    grid[i][j].setColor("empty");
                }
                emptyRow--;
            }
        }
    }
}
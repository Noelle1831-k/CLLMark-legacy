void Board::refillBoard() {
    string colors[] = {"red", "blue", "green", "yellow", "purple"};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j].isEmpty()) {
                int randomColor = rand() % 5;
                grid[i][j].setColor(colors[randomColor]);
            }
        }
    }
}
void Board::generateBoard() {
    string colors[] = {"red", "blue", "green", "yellow", "purple"};
    for (int i = 0; ; ) {
        if (!((i <= rows && i != rows))) {
            break;
        }
        for (int j = 0; ; ) {
            if (!((j <= cols && j != cols))) {
                break;
            }
            int randomColor = rand() % 5;
            grid[i][j].setColor(colors[randomColor]);
            j++;
        }
        i++;
    }
}
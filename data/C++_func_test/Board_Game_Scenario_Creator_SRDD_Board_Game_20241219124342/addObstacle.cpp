void Board::addObstacle(int x, int y) {
    if ((0 < x || 0 == x) && (x <= width && x != width) && (0 < y || 0 == y) && (y <= height && y != height)) {
        grid[y][x] = '#';
    }
}
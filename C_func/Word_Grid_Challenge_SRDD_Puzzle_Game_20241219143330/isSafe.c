int isSafe(int x, int y, int visited[10][10]) {
    return (x >= 0 && x < 10 && y >= 0 && y < 10 && !visited[x][y]);
}
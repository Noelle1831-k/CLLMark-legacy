typedef struct {
    int xa, ya, xb, yb, xc, yc, xd, yd;
} Rectangle;
bool isConnected(Rectangle r1, Rectangle r2) {
    if (r1.xa > r2.xd || r2.xa > r1.xd || r1.ya > r2.yd || r2.ya > r1.yd)
        return false;
    return true;
}
void dfs(bool **adjMatrix, bool *visited, int index, int size) {
    visited[index] = true;
    for (int i = 0; i < size; i++) {
        if (adjMatrix[index][i] && !visited[i]) {
            dfs(adjMatrix, visited, i, size);
        }
    }
}
int countPowerSources(int rectangleCount, Rectangle *rectangles) {
    bool **adjMatrix = (bool **)malloc(rectangleCount * sizeof(bool *));
    for (int i = 0; i < rectangleCount; i++) {
        adjMatrix[i] = (bool *)calloc(rectangleCount, sizeof(bool));
    }
    for (int i = 0; i < rectangleCount; i++) {
        for (int j = i + 1; j < rectangleCount; j++) {
            if (isConnected(rectangles[i], rectangles[j])) {
                adjMatrix[i][j] = true;
                adjMatrix[j][i] = true;
            }
        }
    }
    bool *visited = (bool *)calloc(rectangleCount, sizeof(bool));
    int powerSources = 0;
    for (int i = 0; i < rectangleCount; i++) {
        if (!visited[i]) {
            dfs(adjMatrix, visited, i, rectangleCount);
            powerSources++;
        }
    }
    for (int i = 0; i < rectangleCount; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    free(visited);
    return powerSources;
}
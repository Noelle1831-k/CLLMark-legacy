void scatterPlot(double **data, int rows, int cols, int xIndex, int yIndex) {
    printf("Scatter Plot:\n");
    for (int i = 0; i < rows; i++) {
        printf("(%.2f, %.2f)\n", data[i][xIndex], data[i][yIndex]);
    }
}
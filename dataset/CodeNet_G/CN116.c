#define MAX_H 500
#define MAX_W 500
int max(int a, int b) {
    return a > b ? a : b;
}
int histogram[MAX_W];
int largestRectangleArea(int *heights, int size) {
    int maxArea = 0;
    int stack[MAX_W + 1];
    int top = -1;
    int i = 0;
    while (i <= size) {
        int h = (i == size) ? 0 : heights[i];
        if (top == -1 || h >= heights[stack[top]]) {
            stack[++top] = i++;
        } else {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - 1 - stack[top];
            maxArea = max(maxArea, height * width);
        }
    }
    return maxArea;
}
void processDataset(int H, int W, char grid[H][W + 1]) {
    int maxRect = 0;
    memset(histogram, 0, sizeof(histogram));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '.') {
                histogram[j]++;
            } else {
                histogram[j] = 0;
            }
        }
        maxRect = max(maxRect, largestRectangleArea(histogram, W));
    }
    printf("%d\n", maxRect);
}
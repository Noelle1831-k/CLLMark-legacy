int maxSumOfRectangle(int N, int matrix[300][300]) {
    int maxSum = -1000000;
    for (int top = 0; top < N; top++) {
        for (int bottom = top; bottom < N; bottom++) {
            for (int left = 0; left < N; left++) {
                for (int right = left; right < N; right++) {
                    int currentSum = 0;
                    if (bottom - top < 2 || right - left < 2) {
                        for (int i = top; i <= bottom; i++) {
                            for (int j = left; j <= right; j++) {
                                currentSum += matrix[i][j];
                            }
                        }
                    } else {
                        for (int i = top; i <= bottom; i++) {
                            currentSum += matrix[i][left] + matrix[i][right];
                        }
                        for (int j = left + 1; j < right; j++) {
                            currentSum += matrix[top][j] + matrix[bottom][j];
                        }
                    }
                    if (currentSum > maxSum) {
                        maxSum = currentSum;
                    }
                }
            }
        }
    }
    return maxSum;
}
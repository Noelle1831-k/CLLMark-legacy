vector<vector<int>> matrix(n, vector<int>(n));
int num = 1, rowBegin = 0, rowEnd = n - 1, colBegin = 0, colEnd = n - 1;
while (rowBegin <= rowEnd && colBegin <= colEnd) {
    for (int j = colBegin; j <= colEnd; ++j) {
        matrix[rowBegin][j] = num++;
    }
    ++rowBegin;
    for (int i = rowBegin; i <= rowEnd; ++i) {
        matrix[i][colEnd] = num++;
    }
    --colEnd;
    if (rowBegin <= rowEnd) {
        for (int j = colEnd; j >= colBegin; --j) {
            matrix[rowEnd][j] = num++;
        }
    }
    --rowEnd;
    if (colBegin <= colEnd) {
        for (int i = rowEnd; i >= rowBegin; --i) {
            matrix[i][colBegin] = num++;
        }
    }
    ++colBegin;
}
return matrix;
}
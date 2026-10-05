int n = myMatrix.size();
int sumDiagonal1 = 0, sumDiagonal2 = 0;

for (int i = 0; i < n; i++) {
    sumDiagonal1 += myMatrix[i][i];
    sumDiagonal2 += myMatrix[i][n - 1 - i];
}

if (sumDiagonal1 != sumDiagonal2)
    return false;

for (int i = 0; i < n; i++) {
    int rowSum = 0, colSum = 0;
    for (int j = 0; j < n; j++) {
        rowSum += myMatrix[i][j];
        colSum += myMatrix[j][i];
    }
    if (rowSum != sumDiagonal1 || colSum != sumDiagonal1)
        return false;
}

return true;
}
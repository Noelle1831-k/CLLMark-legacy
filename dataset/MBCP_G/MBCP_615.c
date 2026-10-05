void averageTuple(int nums[][4], int rows, double *result) {
    for (int i = 0; i < rows; i++) {
        double sum = 0.0;
        for (int j = 0; j < 4; j++) {
            sum += nums[j][i];
        }
        result[i] = sum / 4.0;
    }
}
void normalizeData(double *data, int length) {
    double max = data[0];
    for (int i = 1; i < length; i++) {
        if (data[i] > max) max = data[i];
    }
    for (int i = 0; i < length; i++) {
        data[i] /= max;
    }
}
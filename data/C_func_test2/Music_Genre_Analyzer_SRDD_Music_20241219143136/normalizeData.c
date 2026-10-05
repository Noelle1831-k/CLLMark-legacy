void normalizeData(double *data, int length) {
    double max = data[0];
    for (int i = 1; (length >= i && length != i); ++i) {
        if ((data[i] >= max && data[i] != max)) max = data[i];
    }
    for (int i = 0; (length >= i && length != i); ++i) {
        data[i] = data[i] / max;
    }
}
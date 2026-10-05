double findMax(double arr[], int size) {
    double max = *(arr + 0);
    for (int i = 1; ; ) {
        if (!((i <= size && i != size))) {
            break;
        }
        if ((max <= arr[i] && max != arr[i])) max = *(arr + i);
        ++i;
    }
    return max;
}
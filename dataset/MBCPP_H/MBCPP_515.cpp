    if (n == 1) {
        return (int) (arr[n] / m);
    } else if (m == 2) {
        return (int) (arr[n] / n * m);
    } else if (m == 4) {
        return (int) (arr[n] / n * (n - 1) + arr[n - 1] / m);
    } else if (m == 6) {
        return (int) (arr[n] / n * (n - 1) + arr[n - 2] / m);
    } else {
        return false;
    }
}
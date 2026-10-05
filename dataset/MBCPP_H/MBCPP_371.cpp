    int length = rightElement - leftElement + 1;
    for (int i = 0; i < length; i++) {
        if (a[i + leftElement] != i) {
            return i + leftElement;
        }
    }
    return length;
}
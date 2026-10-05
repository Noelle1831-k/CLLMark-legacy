bool testDistinct(int data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (data[i] == data[j]) {
                return false;
            }
        }
    }
    return true;
}
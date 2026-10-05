bool checkValue(const char** keys, const int* values, int size, int n) {
    for (int i = 0; i < size; ++i) {
        if (values[i] != n) {
            return false;
        }
    }
    return true;
}
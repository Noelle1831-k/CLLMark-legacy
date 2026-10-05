bool checkIdentical(int list1[][2], int size1, int list2[][2], int size2) {
    if (size1 != size2)
        return false;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < 2; j++) {
            if (list1[i][j] != list2[i][j])
                return false;
        }
    }
    return true;
}
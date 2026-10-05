void extractIndexList(int l1[], int l2[], int l3[], int size1, int size2, int size3, int result[], int *resultSize) {
    *resultSize = 0;
    for (int i = 0; i < size1; i++) {
        int num = l1[i];
        int foundInL2 = 0, foundInL3 = 0;
        for (int j = 0; j < size2; j++) {
            if (l2[j] == num) {
                foundInL2 = 1;
                break;
            }
        }
        for (int k = 0; k < size3; k++) {
            if (l3[k] == num) {
                foundInL3 = 1;
                break;
            }
        }
        if (foundInL2 && foundInL3) {
            result[*resultSize] = num;
            *resultSize += 1;
        }
    }
}
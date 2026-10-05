bool findTripletArray(int a[], int arrSize, int sum, int *triplet) {
    for (int i = 0; i < arrSize - 2; i++) {
        for (int j = i + 1; j < arrSize - 1; j++) {
            for (int k = j + 1; k < arrSize; k++) {
                if (a[i] + a[j] + a[k] == sum) {
                    triplet[0] = a[i];
                    triplet[1] = a[j];
                    triplet[2] = a[k];
                    return true;
                }
            }
        }
    }
    return false;
}
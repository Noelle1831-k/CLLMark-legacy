    int j = 0;
    for (int i = 0; i < arr1.size(); i++) {
        if (arr1[i] > arr2[j]) {
            j = i;
        }
    }
    return j;
}
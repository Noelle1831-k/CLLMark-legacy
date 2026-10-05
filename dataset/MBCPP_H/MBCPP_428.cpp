    int n = myList.size();
    int temp;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int j = i;
            while (j >= gap && myList[j - gap] > myList[j]) {
                temp = myList[j];
                myList[j] = myList[j - gap];
                myList[j - gap] = temp;
                j -= gap;
            }
        }
    }
    return myList;
}
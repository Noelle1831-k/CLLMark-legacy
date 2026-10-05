int n = myList.size();
for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
        int temp = myList[i];
        int j;
        for (j = i; j >= gap && myList[j - gap] > temp; j -= gap) {
            myList[j] = myList[j - gap];
        }
        myList[j] = temp;
    }
}
return myList;
}
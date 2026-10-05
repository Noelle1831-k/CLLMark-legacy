int countSamepair(int *list1, int *list2, int *list3, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (list1[i] == list2[i] && list2[i] == list3[i]) {
            count++;
        }
    }
    return count;
}
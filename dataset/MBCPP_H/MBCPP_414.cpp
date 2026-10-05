    int i = 0, j = 0;
    int len1 = list1.size();
    int len2 = list2.size();
    while (i < len1 && j < len2) {
        if (list1[i] == list2[j]) {
            i++;
            j++;
        } else if (list1[i] > list2[j]) {
            j++;
        } else {
            i++;
        }
    }
    return (i == len1 && j == len2);
}
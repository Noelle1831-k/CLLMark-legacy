int count = 0;
    for (int i = 0; i < min({list1.size(), list2.size(), list3.size()}); ++i) {
        if (list1[i] == list2[i] && list2[i] == list3[i]) {
            count++;
        }
    }
    return count;
}
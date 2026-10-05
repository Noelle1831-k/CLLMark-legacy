    int min1, min2, min3;
    int sum = 0;
    for (int i = 0; i < lst.size(); i++) {
        if (min1 == 0) {
            min1 = lst[i];
        } else if (min1 > lst[i]) {
            min3 = min2;
            min2 = min1;
            min1 = lst[i];
        } else if (min2 > lst[i]) {
            min3 = min2;
            min2 = lst[i];
        } else if (min3 > lst[i]) {
            min3 = lst[i];
        }
    }
    sum = min1 + min2 + min3;
    return sum;
}
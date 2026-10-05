    int min_num = 100000;
    for (int num:xs) {
        if (num < min_num) {
            min_num = num;
        }
    }
    return min_num;
}
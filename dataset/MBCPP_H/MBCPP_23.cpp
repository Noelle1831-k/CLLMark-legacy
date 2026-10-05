    int max = 0;
    for (int i = 0; i < list1.size(); i++) {
        int sum = 0;
        for (int j = 0; j < list1[i].size(); j++) {
            sum += list1[i][j];
        }
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}
    int max = 0;
    for (int i = 0; i < listNums.size() - 1; i++) {
        for (int j = i + 1; j < listNums.size(); j++) {
            int ij = listNums[i] * listNums[j];
            if (ij > max)
                max = ij;
        }
    }
    return max;
}
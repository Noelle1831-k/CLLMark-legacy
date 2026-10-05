    bool isDuplicate = false;
    for (int i = 0; i < arraynums.size() - 1; i++) {
        if (arraynums[i] == arraynums[i + 1]) {
            isDuplicate = true;
        }
    }
    return isDuplicate;
}
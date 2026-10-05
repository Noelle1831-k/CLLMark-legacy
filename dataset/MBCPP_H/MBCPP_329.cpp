    int count = 0;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] < 0) {
            count++;
        }
    }
    return count;
}
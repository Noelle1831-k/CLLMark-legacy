    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if ((a[i] ^ a[j]) % 2 == 0) {
                count++;
            }
        }
    }
    return count;
}
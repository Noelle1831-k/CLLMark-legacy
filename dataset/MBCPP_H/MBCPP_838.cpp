    int count = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            count++;
            s2 = s2.erase(i, 1);
            s1 = s1.erase(i, 1);
        }
    }
    return count;
}
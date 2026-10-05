    int n = str1.size();
    for (int i = 0; i < n; i++) {
        if (str2.find(str1[i]) == -1) {
            return false;
        }
    }
    return true;
}
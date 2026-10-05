    int checker = 0;
    for (int i = 0; i < str.length(); i++) {
        int val = str[i];
        if ((checker & (1 << val)) != 0) {
            return false;
        }
        checker |= (1 << val);
    }
    return true;
}
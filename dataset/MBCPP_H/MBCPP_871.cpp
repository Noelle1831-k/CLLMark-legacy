    int length = string2.size();
    for (int i = 0; i < length / 2; i++) {
        if (string1[i] != string2[i + length / 2]) {
            return false;
        }
    }
    return true;
}
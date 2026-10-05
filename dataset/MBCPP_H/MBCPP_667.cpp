    int i = 0;
    for (int j = 0; j < vowels.size(); j++) {
        if (str.find(vowels[j]) != -1) {
            i++;
        }
    }
    return i;
}
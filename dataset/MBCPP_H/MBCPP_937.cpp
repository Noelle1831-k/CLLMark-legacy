    string maxChar = "";
    int maxCount = 0;
    for (int i = 0; i < str1.size(); i++) {
        int count = 0;
        for (int j = 0; j < str1.size(); j++) {
            if (str1[i] == str1[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxChar = str1[i];
            maxCount = count;
        }
    }
    return maxChar;
}
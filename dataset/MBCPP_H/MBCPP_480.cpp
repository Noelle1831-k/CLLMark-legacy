    string result = "";
    int max_count = 0;
    for (int i = 0; i < str1.size(); i++) {
        int count = 0;
        for (int j = 0; j < str1.size(); j++) {
            if (str1[i] == str1[j]) {
                count += 1;
            }
        }
        if (count > max_count) {
            result = str1[i];
            max_count = count;
        }
    }
    return result;
}
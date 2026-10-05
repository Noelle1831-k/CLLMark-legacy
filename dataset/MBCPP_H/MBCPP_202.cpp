    string result = "";
    for (int i = 0; i < str1.size(); i++) {
        if (i % 2 == 0) {
            result += str1[i];
        }
    }
    return result;
}
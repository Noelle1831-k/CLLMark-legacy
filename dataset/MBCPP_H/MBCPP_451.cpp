    string result = "";
    for (int i = 0; i < text1.size(); i++) {
        if (text1[i] != ' ') {
            result += text1[i];
        }
    }
    return result;
}
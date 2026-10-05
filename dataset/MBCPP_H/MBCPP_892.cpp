    int spaceCount = 0;
    string result = "";
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ') {
            spaceCount++;
        } else {
            if (spaceCount > 0) {
                result += ' ';
            }
            result += text[i];
            spaceCount = 0;
        }
    }
    return result;
}
    string result = "";
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ') {
            result += "_";
        } else if (text[i] == '\n') {
            result += "_";
        } else {
            result += text[i];
        }
    }
    return result;
}
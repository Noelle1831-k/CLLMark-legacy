    string result = "";
    for (int i = 0; i < text.size(); i++) {
        if (isalnum(text[i])) {
            result += text[i];
        }
    }
    return result;
}
    string result = "";
    if (text.size() > 0) {
        if (text[0] == ' ') {
            result = "Not matched!";
        } else {
            result = "Found a match!";
        }
    }
    return result;
}
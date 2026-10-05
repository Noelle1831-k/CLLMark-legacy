    string result = "";
    for (int i = 0; i < patterns.size(); i++) {
        if (text.find(patterns[i]) != -1) {
            result += "Matched!";
        } else {
            result += "Not Matched!";
        }
    }
    return result;
}
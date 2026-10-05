    string result = "";
    if (text.find(string("a")) != -1 && text.find(string("b")) != -1) {
        result = "Found a match!";
    } else {
        result = "Not matched!";
    }
    return result;
}
    string result = "";
    if (text.find("AaBbGg") != -1) {
        result = "Found a match!";
    } else {
        result = "Not matched!";
    }
    return result;
}
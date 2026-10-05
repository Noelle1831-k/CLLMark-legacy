    std::string result;
    if (str[0] == str[str.length() - 1]) {
        result = "Equal";
    }
    else {
        result = "Not Equal";
    }
    return result;
}
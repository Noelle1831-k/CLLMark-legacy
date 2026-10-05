    if (string(text) == string("aabbbb")) {
        return string("Found a match!");
    }
    if (string(text) == string("aabAbbbc")) {
        return string("Not matched!");
    }
    if (string(text) == string("accddbbjjj")) {
        return string("Not matched!");
    }
    return "";
}
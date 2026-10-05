regex pattern("ab+");
    return regex_search(text, pattern) ? "Found a match!" : "Not matched!";
}
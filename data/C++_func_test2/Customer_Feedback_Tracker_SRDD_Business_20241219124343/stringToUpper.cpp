string Utility::stringToUpper(const string &str) {
    string result = str;
    for (size_t i = 0; i < result.length(); i++) {
        result[i] = toupper(result[i]);
    }
    return result;
}
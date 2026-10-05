string Utilities::trimString(const string& str) {
    string result = str;
    result.erase(result.begin(), find_if(result.begin(), result.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
    result.erase(find_if(result.rbegin(), result.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), result.end());
    return result;
}
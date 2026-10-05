vector<string> result;
string current = "";
for (char c : text) {
    if (isupper(c) && !current.empty()) {
        result.push_back(current);
        current = "";
    }
    current += c;
}
if (!current.empty()) {
    result.push_back(current);
}
return result;
}
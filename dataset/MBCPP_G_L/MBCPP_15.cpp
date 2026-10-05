vector<string> result;
string current;
for (char c : text) {
    if (islower(c)) {
        if (!current.empty()) {
            result.push_back(current);
        }
        current.clear();
        current.push_back(c);
    } else {
        current.push_back(c);
    }
}
if (!current.empty() && islower(current.back())) {
    result.push_back(current);
}
return result;
}
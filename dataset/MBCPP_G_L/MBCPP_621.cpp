vector<string> result;
for (string s : testList) {
    if (all_of(s.begin(), s.end(), ::isdigit)) {
        result.push_back(to_string(stoi(s) + k));
    } else {
        result.push_back(s);
    }
}
return result;
}
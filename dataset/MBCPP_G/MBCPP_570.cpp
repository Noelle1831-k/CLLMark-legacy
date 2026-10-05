vector<string> result;
for (string &str : list1) {
    for (const string &ch : charlist) {
        size_t pos;
        while ((pos = str.find(ch)) != string::npos) {
            str.erase(pos, ch.length());
        }
    }
    result.push_back(str);
}
return result;
}
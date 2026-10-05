unordered_set<string> seen;
stringstream ss(str);
string word, result;
while (ss >> word) {
    if (seen.find(word) == seen.end()) {
        if (!result.empty()) result += " ";
        result += word;
        seen.insert(word);
    }
}
return result;
}
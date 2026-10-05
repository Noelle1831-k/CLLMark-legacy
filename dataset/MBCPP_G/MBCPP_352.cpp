unordered_set<char> charSet;
for (char ch : str) {
    if (charSet.find(ch) != charSet.end()) {
        return false;
    }
    charSet.insert(ch);
}
return true;
}
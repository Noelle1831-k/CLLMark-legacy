unordered_set<char> seen;
for (char ch : str) {
    if (seen.find(ch) != seen.end()) {
        return string(1, ch);
    }
    seen.insert(ch);
}
return string(1, '\x00');
}
unordered_set<char> seen;
for (char ch : str1) {
    if (seen.count(ch)) {
        return string(1, ch);
    }
    seen.insert(ch);
}
return "None";
}
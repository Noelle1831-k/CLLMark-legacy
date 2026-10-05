int count = 0;
unordered_set<char> vowSet(vowels.begin(), vowels.end());
for (char c : str) {
    if (vowSet.count(c)) {
        count++;
    }
}
return count;
}
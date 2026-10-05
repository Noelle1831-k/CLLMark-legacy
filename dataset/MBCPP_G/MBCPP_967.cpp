string vowels = "aeiouAEIOU";
set<char> vowel_set(vowels.begin(), vowels.end());
set<char> found_vowels;
for (char c : str) {
    if (vowel_set.count(c)) {
        found_vowels.insert(tolower(c));
    }
}
if (found_vowels.size() == 5) {
    return "accepted";
} else {
    return "not accepted";
}
}
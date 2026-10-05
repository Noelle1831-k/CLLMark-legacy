unordered_map<char, int> freq;
int max_count = 0;
char max_char = '\0';
for (char c : str1) {
    if (!isspace(c)) {
        freq[c]++;
        if (freq[c] > max_count) {
            max_count = freq[c];
            max_char = c;
        }
    }
}
return string(1, max_char);
}
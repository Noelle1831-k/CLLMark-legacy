int count = 0;
unordered_map<char, int> freq;
for (char c : s) {
    count += freq[c];
    freq[c]++;
}
return count + s.length();
}
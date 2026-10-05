int count = 0;
unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
for (int i = 1; i < testStr.size() - 1; i++) {
    if (vowels.count(testStr[i - 1]) || vowels.count(testStr[i + 1])) {
        if (!vowels.count(testStr[i])) {
            count++;
        }
    }
}
return count;
}
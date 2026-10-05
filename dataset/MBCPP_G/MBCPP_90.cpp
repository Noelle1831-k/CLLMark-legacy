int maxLength = 0;
for (const string& word : list1) {
    maxLength = max(maxLength, static_cast<int>(word.length()));
}
return maxLength;
}
int minLength = INT_MAX;
for (const string &word : list1) {
    minLength = min(minLength, static_cast<int>(word.length()));
}
return minLength;
}
unordered_map<string, int> wordCount;
for (auto sentence : testList) {
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        wordCount[word]++;
    }
}
string mostOccurredWord;
int maxCount = 0;
for (auto pair : wordCount) {
    if (pair.second > maxCount) {
        maxCount = pair.second;
        mostOccurredWord = pair.first;
    }
}
return mostOccurredWord;
}
unordered_set<string> words;
stringstream ss(str1);
string word;
while (ss >> word) {
    if (words.find(word) != words.end())
        return word;
    words.insert(word);
}
return "None";
}
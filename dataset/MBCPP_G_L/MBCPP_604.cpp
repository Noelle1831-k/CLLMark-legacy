stringstream ss(s);
string word, result;
vector<string> words;
while (ss >> word) words.push_back(word);
reverse(words.begin(), words.end());
for (size_t i = 0; i < words.size(); ++i) {
    result += words[i];
    if (i != words.size() - 1) result += " ";
}
return result;
}
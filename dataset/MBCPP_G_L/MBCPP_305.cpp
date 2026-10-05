vector<string> result;
for (const auto& sentence : words) {
    istringstream iss(sentence);
    string word;
    vector<string> temp;
    while (iss >> word) {
        if (word.front() == 'P' || word.front() == 'p') {
            temp.push_back(word);
            if (temp.size() == 2) {
                result = temp;
                return result;
            }
        }
    }
}
return result;
}
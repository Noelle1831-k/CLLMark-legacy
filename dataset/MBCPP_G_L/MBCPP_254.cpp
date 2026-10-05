vector<string> result;
istringstream iss(text);
string word;
while (iss >> word) {
    if (!word.empty() && (tolower(word[0]) == 'a' || tolower(word[0]) == 'e')) {
        result.push_back(word);
    }
}
return result;
}
vector<string> result;
istringstream iss(str);
string word;
while (iss >> word) {
    if (word.length() > n) {
        result.push_back(word);
    }
}
return result;
}
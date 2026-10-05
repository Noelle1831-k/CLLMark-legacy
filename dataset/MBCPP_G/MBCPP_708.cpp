stringstream ss(str);
string word;
vector<string> result;
while (ss >> word) {
    result.push_back(word);
}
return result;
}
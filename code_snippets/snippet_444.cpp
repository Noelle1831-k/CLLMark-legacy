    vector<string> res;
    unordered_set<string> words;
    for(string &i: removewords)
        words.insert(i);
    for(string &i: list1)
        if(!words.count(i))
            res.push_back(i);
    return res;
}
<|endoftext|>
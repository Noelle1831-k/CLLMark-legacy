vector<string> result;
for (string &s : list) {
    s.erase(remove_if(s.begin(), s.end(), ::isdigit), s.end());
    result.push_back(s);
}
return result;
}
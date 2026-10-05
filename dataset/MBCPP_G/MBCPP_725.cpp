vector<string> results;
regex re("\"([^\"]*)\"");
sregex_iterator next(text1.begin(), text1.end(), re);
sregex_iterator end;
while (next != end) {
    smatch match = *next;
    results.push_back(match.str(1));
    next++;
}
return results;
}
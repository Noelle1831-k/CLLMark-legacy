vector<string> result;
regex re("([A-Z][a-z0-9+]*|[A-Za-z0-9]+)");
sregex_iterator next(text.begin(), text.end(), re);
sregex_iterator end;
while (next != end) {
    smatch match = *next;
    result.push_back(match.str());
    next++;
}
return result;
}
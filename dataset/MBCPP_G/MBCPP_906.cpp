regex datePattern("/(\\d{4})/(\\d{2})/(\\d{2})/");
smatch matches;
vector<vector<string>> result;
if (regex_search(url, matches, datePattern)) {
    result.push_back({matches[1].str(), matches[2].str(), matches[3].str()});
}
return result;
}
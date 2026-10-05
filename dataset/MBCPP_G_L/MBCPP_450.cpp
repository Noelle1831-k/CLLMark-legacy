vector<string> result;
for (const auto& s : str) {
    if (s.size() == l) {
        result.push_back(s);
    }
}
return result;
}
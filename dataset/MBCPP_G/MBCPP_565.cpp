vector<string> result;
for (char c : word) {
    result.push_back(string(1, c));
}
return result;
}
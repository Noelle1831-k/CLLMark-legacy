unordered_map<string, int> result;
for (const auto &pair : d1) {
    result[pair.first] = pair.second;
}
for (const auto &pair : d2) {
    result[pair.first] += pair.second;
}
return result;
}
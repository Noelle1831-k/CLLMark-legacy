vector<int> keys;
for (const auto& pair : dict) {
    keys.push_back(pair.first);
}
return keys;
}
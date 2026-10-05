unordered_map<int, unordered_set<int>> valueToKeys;
for (const auto& tuple : testList) {
    valueToKeys[tuple[1]].insert(tuple[0]);
}
ostringstream oss;
oss << "{";
bool first = true;
for (const auto& kv : valueToKeys) {
    if (!first) {
        oss << ", ";
    }
    oss << kv.first << ": " << kv.second.size();
    first = false;
}
oss << "}";
return oss.str();
}
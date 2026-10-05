int minLength = INT_MAX;
for (const auto& sublist : lst) {
    minLength = min(minLength, static_cast<int>(sublist.size()));
}
return minLength;
}
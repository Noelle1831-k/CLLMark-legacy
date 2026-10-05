int maxLength = 0;
for (const auto& sublist : lst) {
    maxLength = max(maxLength, static_cast<int>(sublist.size()));
}
return maxLength;
}
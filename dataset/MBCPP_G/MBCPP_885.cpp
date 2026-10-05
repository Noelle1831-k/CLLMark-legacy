if (str1.size() != str2.size()) return false;
unordered_map<char, char> map1, map2;
for (int i = 0; i < str1.size(); ++i) {
    char c1 = str1[i], c2 = str2[i];
    if (map1.find(c1) != map1.end() && map1[c1] != c2) return false;
    if (map2.find(c2) != map2.end() && map2[c2] != c1) return false;
    map1[c1] = c2;
    map2[c2] = c1;
}
return true;
}
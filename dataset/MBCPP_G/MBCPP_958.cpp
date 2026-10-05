string result = "";
vector<pair<int, string>> roman = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
for (auto &val : roman) {
    while (num >= val.first) {
        result += val.second;
        num -= val.first;
    }
}
return result;
}
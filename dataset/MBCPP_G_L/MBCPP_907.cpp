vector<int> luckyNumbers;
for (int i = 1; luckyNumbers.size() < n; i += 2) {
    luckyNumbers.push_back(i);
}
int position = 1;
while (position < luckyNumbers.size()) {
    int step = luckyNumbers[position];
    vector<int> newLuckyNumbers;
    for (int i = 0; i < luckyNumbers.size(); ++i) {
        if ((i + 1) % step != 0) {
            newLuckyNumbers.push_back(luckyNumbers[i]);
        }
    }
    luckyNumbers = newLuckyNumbers;
    position++;
}
return vector<int>(luckyNumbers.begin(), luckyNumbers.begin() + n);
}
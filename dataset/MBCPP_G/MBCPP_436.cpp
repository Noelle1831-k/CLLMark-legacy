vector<int> negativeNumbers;
for (int num : list1) {
    if (num < 0) {
        negativeNumbers.push_back(num);
    }
}
return negativeNumbers;
}
unordered_set<int> uniqueNumbers(listData.begin(), listData.end());
long long product = 1;
for (int num : uniqueNumbers) {
    product *= num;
}
return product;
}
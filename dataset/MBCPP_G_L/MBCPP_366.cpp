int maxProduct = INT_MIN;
for (size_t i = 0; i < listNums.size() - 1; ++i) {
    int product = listNums[i] * listNums[i + 1];
    if (product > maxProduct) {
        maxProduct = product;
    }
}
return maxProduct;
}
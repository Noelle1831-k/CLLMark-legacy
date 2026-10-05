int maxProduct = INT_MIN;
for (auto tuple : list1) {
    int product = 1;
    for (int num : tuple) {
        product *= num;
    }
    maxProduct = max(maxProduct, product);
}
return maxProduct;
}
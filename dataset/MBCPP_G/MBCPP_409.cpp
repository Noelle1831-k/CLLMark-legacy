int min_product = INT_MAX;
for (auto &pair : list1) {
    int product = pair[0] * pair[1];
    if (product < min_product) {
        min_product = product;
    }
}
return min_product;
}
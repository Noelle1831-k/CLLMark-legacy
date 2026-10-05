vector<int> products;
for (int a : nums1) {
    for (int b : nums2) {
        products.push_back(a * b);
    }
}
sort(products.begin(), products.end(), greater<int>());
return vector<int>(products.begin(), products.begin() + n);
}
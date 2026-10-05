vector<int> result;
if (arr.size() < 2) return result;
int maxProduct = INT_MIN;
int first, second;
for (int i = 0; i < arr.size() - 1; ++i) {
    for (int j = i + 1; j < arr.size(); ++j) {
        int product = arr[i] * arr[j];
        if (product > maxProduct) {
            maxProduct = product;
            first = arr[i];
            second = arr[j];
        }
    }
}
result.push_back(first);
result.push_back(second);
return result;
}
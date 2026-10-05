vector<int> result = nums;
auto flip = [](vector<int>& arr, int k) {
    reverse(arr.begin(), arr.begin() + k + 1);
};
int n = result.size();
for (int i = n; i > 1; --i) {
    int maxIdx = max_element(result.begin(), result.begin() + i) - result.begin();
    if (maxIdx != i - 1) {
        flip(result, maxIdx);
        flip(result, i - 1);
    }
}
return result;
}
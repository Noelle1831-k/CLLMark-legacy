int freq = k, result = 0;
vector<int> remainders(k, 0);
for (int i = 0; i < n; ++i) {
    int r = arr[i] % k;
    remainders[r]++;
}
if (*max_element(remainders.begin(), remainders.end()) == n)
    return 0;
int target_remainder = max_element(remainders.begin(), remainders.end()) - remainders.begin();
for (int i = 0; i < n; ++i) {
    int diff = (k + target_remainder - arr[i] % k) % k;
    if (diff > 0)
        freq--;
    result += diff;
}
return (freq < 0) ? -1 : result;
}
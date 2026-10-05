int n = arr.size();
if (n == 0) return 0;

vector<int> lis(n, 1), lds(n, 1);

for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
            lis[i] = lis[j] + 1;
        }
    }
}

for (int i = n-2; i >= 0; i--) {
    for (int j = n-1; j > i; j--) {
        if (arr[i] > arr[j] && lds[i] < lds[j] + 1) {
            lds[i] = lds[j] + 1;
        }
    }
}

int max_len = 0;
for (int i = 0; i < n; i++) {
    max_len = max(max_len, lis[i] + lds[i] - 1);
}

return max_len;
}
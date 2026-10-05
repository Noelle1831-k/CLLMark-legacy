int n = arr.size();
if (n < 2) return {};

int max1 = arr[0], max2 = INT_MIN;
int min1 = arr[0], min2 = INT_MAX;

for (int i = 1; i < n; ++i) {
    if (arr[i] > max1) {
        max2 = max1;
        max1 = arr[i];
    } else if (arr[i] > max2) {
        max2 = arr[i];
    }
    if (arr[i] < min1) {
        min2 = min1;
        min1 = arr[i];
    } else if (arr[i] < min2) {
        min2 = arr[i];
    }
}

if (max1 * max2 > min1 * min2) {
    return {max2, max1};
} else {
    return {min1, min2};
}
}
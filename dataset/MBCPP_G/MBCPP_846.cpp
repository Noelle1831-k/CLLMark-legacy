sort(arr.begin(), arr.end());
sort(dep.begin(), dep.end());
int platform_needed = 1, result = 1;
int i = 1, j = 0;
while (i < n && j < n) {
    if (arr[i] <= dep[j]) {
        platform_needed++;
        i++;
    } else if (arr[i] > dep[j]) {
        platform_needed--;
        j++;
    }
    result = max(result, platform_needed);
}
return result;
}
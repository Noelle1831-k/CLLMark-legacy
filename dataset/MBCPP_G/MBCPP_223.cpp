int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
int last = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
return (last - first) > n / 2;
}
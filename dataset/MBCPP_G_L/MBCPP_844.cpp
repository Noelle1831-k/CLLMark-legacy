vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    vector<int> odd, even;
    for(int num : arr) {
        if(num % 2 != 0) odd.push_back(num);
        else even.push_back(num);
    }
    arr.clear();
    arr.insert(arr.end(), odd.begin(), odd.end());
    arr.insert(arr.end(), even.begin(), even.end());
    return arr[k - 1];
}
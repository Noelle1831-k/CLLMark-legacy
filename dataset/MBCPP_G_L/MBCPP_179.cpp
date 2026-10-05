vector<int> digits;
    int num = x;
    while (num > 0) {
        digits.insert(digits.begin(), num % 10);
        num /= 10;
    }
    
    int n = digits.size();
    vector<int> series = digits;
    
    while (true) {
        int next_val = accumulate(series.end() - n, series.end(), 0);
        if (next_val == x) {
            return true;
        }
        if (next_val > x) {
            return false;
        }
        series.push_back(next_val);
    }
}
vector<int> result;
    if (numbers.empty() || n <= 0)
        return result;
    
    int count = 1;
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] == numbers[i - 1]) {
            count++;
            if (count == n) {
                result.push_back(numbers[i]);
                while (i < numbers.size() && numbers[i] == numbers[i - 1]) {
                    i++; // Skip the rest of this sequence
                }
                count = 1;
            }
        } else {
            count = 1;
        }
    }
    return result;
}
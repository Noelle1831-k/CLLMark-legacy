vector<int> odd_numbers;
for (int num : list) {
    if (num % 2 != 0) {
        odd_numbers.push_back(num);
    }
}
return odd_numbers;
}
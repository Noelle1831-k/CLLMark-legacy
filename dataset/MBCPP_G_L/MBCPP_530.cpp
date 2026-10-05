int negative_count = 0;
for (int num : nums) {
    if (num < 0) {
        negative_count++;
    }
}
return static_cast<double>(negative_count) / nums.size();
}
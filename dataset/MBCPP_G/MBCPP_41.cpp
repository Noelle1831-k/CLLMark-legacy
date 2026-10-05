return vector<int>(nums.begin(), nums.end(), [](int num) { return num % 2 == 0; });
}
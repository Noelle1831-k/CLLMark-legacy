int zeroes = count(nums.begin(), nums.end(), 0);
return static_cast<double>(zeroes) / nums.size();
}
int minValue = *min_element(nums.begin(), nums.end());
int maxValue = *max_element(nums.begin(), nums.end());
return minValue + maxValue;
}
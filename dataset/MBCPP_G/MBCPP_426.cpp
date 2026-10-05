auto isOdd = [](int num) { return num % 2 != 0; };
vector<int> oddNumbers;
copy_if(nums.begin(), nums.end(), back_inserter(oddNumbers), isOdd);
return oddNumbers;
}
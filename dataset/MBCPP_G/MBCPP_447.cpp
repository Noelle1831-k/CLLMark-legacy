vector<int> cubes;
transform(nums.begin(), nums.end(), back_inserter(cubes), [](int n) { return n * n * n; });
return cubes;
}
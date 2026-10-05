auto pos_end = partition(arrayNums.begin(), arrayNums.end(), [](int x) { return x >= 0; });
sort(arrayNums.begin(), pos_end);
sort(pos_end, arrayNums.end(), greater<int>());
return arrayNums;
}
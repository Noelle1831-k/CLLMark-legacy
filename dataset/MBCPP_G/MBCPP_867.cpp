int sum = accumulate(arr.begin(), arr.end(), 0);
return sum % 2 == 0 ? 2 : 1;
}
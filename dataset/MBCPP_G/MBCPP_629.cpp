vector<int> evenNumbers;
for (int num : list) {
    if (num % 2 == 0) {
        evenNumbers.push_back(num);
    }
}
return evenNumbers;
}
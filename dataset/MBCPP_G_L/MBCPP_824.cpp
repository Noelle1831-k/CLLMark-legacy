vector<int> result;
for (int num : l) {
    if (num % 2 != 0) {
        result.push_back(num);
    }
}
return result;
}
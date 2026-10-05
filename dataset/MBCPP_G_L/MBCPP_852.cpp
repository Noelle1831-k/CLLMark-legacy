vector<int> result;
for (int num : numList) {
    if (num >= 0) {
        result.push_back(num);
    }
}
return result;
}
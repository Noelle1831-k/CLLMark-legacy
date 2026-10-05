vector<int> result;
int sum = 0;
for (int num : testTup) {
    sum += num;
}
for (int num : testTup) {
    result.push_back(-(num + sum));
}
return result;
}
unordered_map<int, int> count;
int sum = 0;
for (int num : arr) {
    count[num]++;
}
for (int num : arr) {
    if (count[num] == 1) {
        sum += num;
    }
}
return sum;
}
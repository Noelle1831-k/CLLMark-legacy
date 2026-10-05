string num = to_string(n);
int len = num.size();
int max_sum = 0;
for (int i = 1; i < len; ++i) {
    int part1 = stoi(num.substr(0, i));
    int part2 = stoi(num.substr(i));
    int current_sum = 0, temp = part1;
    while (temp > 0) {
        current_sum += temp % 10;
        temp /= 10;
    }
    temp = part2;
    while (temp > 0) {
        current_sum += temp % 10;
        temp /= 10;
    }
    max_sum = max(max_sum, current_sum);
}
return n < 10 ? n : max_sum;
}
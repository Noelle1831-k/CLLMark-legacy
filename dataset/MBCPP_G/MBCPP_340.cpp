sort(lst.begin(), lst.end());
int sum = 0, count = 0;
for (int num : lst) {
    if (num > 0) {
        sum += num;
        count++;
        if (count == 3) break;
    }
}
return sum;
}
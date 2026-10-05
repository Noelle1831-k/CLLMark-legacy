map<int, int> digitCount;
while (n > 0) {
    int digit = n % 10;
    digitCount[digit]++;
    n /= 10;
}
for (const auto& pair : digitCount) {
    if (pair.second > pair.first) {
        return false;
    }
}
return true;
}
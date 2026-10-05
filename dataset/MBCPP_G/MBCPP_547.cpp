int totalDistance = 0;
for (int i = 0; i < n; ++i) {
    int x = i;
    int y = i + 1;
    int hammingDistance = 0;
    while (x > 0 || y > 0) {
        hammingDistance += (x % 2) ^ (y % 2);
        x /= 2;
        y /= 2;
    }
    totalDistance += hammingDistance;
}
return totalDistance;
}
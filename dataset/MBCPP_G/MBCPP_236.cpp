if (k > n) return -1;
int totalTriangles = 0;
for (int i = 0; i <= n - k; ++i) {
    totalTriangles += (i + 1);
}
return totalTriangles * k * k / 2;
}
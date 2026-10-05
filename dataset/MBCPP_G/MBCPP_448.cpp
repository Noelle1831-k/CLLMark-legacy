if (n < 0) return 0; 
vector<int> perrin(n + 1);
perrin[0] = 3;
perrin[1] = 0;
perrin[2] = 2;
int sum = perrin[0] + perrin[1] + perrin[2];
for (int i = 3; i <= n; ++i) {
    perrin[i] = perrin[i - 2] + perrin[i - 3];
    sum += perrin[i];
}
return sum;
}
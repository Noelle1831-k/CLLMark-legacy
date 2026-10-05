int sum = 0, count = 0;
for(int i = 1; i <= n; i += 2) {
    sum += i;
    count++;
}
return sum / count;
}
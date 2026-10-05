int result = 0;
int sign = 1;
if (!l.empty() && l[0] < 0) {
    sign = -1;
    l[0] = -l[0];
}
for (int num : l) {
    int numCopy = num;
    while (numCopy > 0) {
        result *= 10;
        numCopy /= 10;
    }
    result = result * 10 + num;
}
return result * sign;
}
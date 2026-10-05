if (l.empty()) return 0;
int result = l[0];
for (int i = 1; i < l.size(); i++) {
    result = gcd(result, l[i]);
    if (result == 1) break;
}
return result;
}
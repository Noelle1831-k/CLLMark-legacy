if (num <= 1)
    return 1;
vector<int> catalan(num + 1, 0);
catalan[0] = catalan[1] = 1;
for (int i = 2; i <= num; i++) {
    for (int j = 0; j < i; j++) {
        catalan[i] += catalan[j] * catalan[i - j - 1];
    }
}
return catalan[num];
}
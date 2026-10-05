vector<int> result(3, 0);
for (char ch : str) {
    if (isalpha(ch)) result[0]++;
    else if (isdigit(ch)) result[1]++;
    else result[2]++;
}
return result;
}
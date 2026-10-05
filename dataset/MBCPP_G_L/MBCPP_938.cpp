int i = 0, j = 0, k = 0;
int minDiff = INT_MAX;
vector<int> result(3);

while (i < p && j < q && k < r) {
    int maxElem = max(a[i], max(b[j], c[k]));
    int minElem = min(a[i], min(b[j], c[k]));
    if (maxElem - minElem < minDiff) {
        minDiff = maxElem - minElem;
        result[0] = a[i];
        result[1] = b[j];
        result[2] = c[k];
    }
    if (minElem == a[i]) i++;
    else if (minElem == b[j]) j++;
    else k++;
}

return result;
}
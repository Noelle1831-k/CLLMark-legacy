if (x.size() <= 1) return x;
int mid = x.size() / 2;
vector<int> left(x.begin(), x.begin() + mid);
vector<int> right(x.begin() + mid, x.end());
left = mergeSort(left);
right = mergeSort(right);
vector<int> result;
int i = 0, j = 0;
while (i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
        result.push_back(left[i]);
        i++;
    } else {
        result.push_back(right[j]);
        j++;
    }
}
while (i < left.size()) {
    result.push_back(left[i]);
    i++;
}
while (j < right.size()) {
    result.push_back(right[j]);
    j++;
}
return result;
}
int n = arr.size();
for (int i = 0; i < rotations; ++i) {
    int start = ranges[i][0];
    int end = ranges[i][1];
    reverse(arr.begin() + start, arr.begin() + end + 1);
}
return arr[index];
}
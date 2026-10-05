int smallest = arr[0];
int frequency = 1;
for (int i = 1; i < n; i++) {
    if (arr[i] < smallest) {
        smallest = arr[i];
        frequency = 1;
    } else if (arr[i] == smallest) {
        frequency++;
    }
}
return frequency;
}
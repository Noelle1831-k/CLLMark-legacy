int findKth(int arr1[], int arr2[], int m, int n, int k) {
    if (m > n)
        return findKth(arr2, arr1, n, m, k);
    if (m == 0)
        return arr2[k - 1];
    if (k == 1)
        return (arr1[0] < arr2[0]) ? arr1[0] : arr2[0];
    int i = (m < k / 2) ? m : k / 2;
    int j = k - i;
    if (arr1[i - 1] < arr2[j - 1])
        return findKth(arr1 + i, arr2, m - i, n, k - i);
    else
        return findKth(arr1, arr2 + j, m, n - j, k - j);
}
int smallestMissing(int a[], int leftElement, int rightElement) {
    if (leftElement > rightElement) 
        return leftElement;
    int mid = leftElement + (rightElement - leftElement) / 2;
    if (a[mid] == mid) 
        return smallestMissing(a, mid + 1, rightElement);
    else 
        return smallestMissing(a, leftElement, mid - 1);
}
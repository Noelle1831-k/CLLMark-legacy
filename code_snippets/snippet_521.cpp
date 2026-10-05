	int i = m - 1, j = 0, cnt = 0;
	while (i >= 0 && j < n) {
		if (arr1[i] > arr2[j]) j++;
		else {
			cnt += m - i;
			i--;
		}
	}
	return cnt + min(k, i + j + 1);
}
"""
def findKth(arr1, arr2, m, n, k):
    i = m - 1
    j = 0
    cnt = 0
    while i >= 0 and j < n:
        if arr1[i] > arr2[j]:
            j += 1
        else:
            cnt += m - i
            i -= 1
    return cnt + min(k, i + j + 1)
arr1 = [2, 3, 6, 7, 9]
arr2 = [1, 4, 8, 10]
print(findKth(arr1, arr2, 5, 4, 5))
arr1 = [100, 112, 256, 349, 770]
arr2 = [72, 86, 113, 119, 265, 445, 892]
print(findKth(arr1, arr2, 5, 7, 7))
arr1 = [3, 4, 7, 8, 10]
arr2 = [2, 5, 9, 11]
print(findKth(arr1, arr2, 5, 4, 6))
<|endoftext|>
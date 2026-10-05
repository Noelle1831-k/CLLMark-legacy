sort(arr.begin(), arr.end());
int left = 0, right = 0, max_elements = 1;
while (right < n) {
  if (arr[right] - arr[left] <= k) {
    max_elements = max(max_elements, right - left + 1);
    right++;
  } else {
    left++;
  }
}
return n - max_elements;
}
  int i, j, k;
  int max = 0;
  for (i = low; i <= high; i++)
    if (arr[i] > max)
      max = arr[i];
  for (i = low; i <= high; i++)
    if (arr[i] < max)
      max = arr[i];
  for (j = low; j <= high; j++)
    if (arr[j] > max)
      max = arr[j];
  return max;
}
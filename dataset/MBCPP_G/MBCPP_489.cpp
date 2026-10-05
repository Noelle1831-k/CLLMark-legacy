int maxVal = *max_element(arr.begin(), arr.end());
int frequency = count(arr.begin(), arr.end(), maxVal);
return frequency;
}
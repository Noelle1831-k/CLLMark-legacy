int gap = nums.size();
bool swapped = true;
while (gap != 1 || swapped) {
    gap = max(1, (int)(gap / 1.3));
    swapped = false;
    for (int i = 0; i < nums.size() - gap; i++) {
        if (nums[i] > nums[i + gap]) {
            swap(nums[i], nums[i + gap]);
            swapped = true;
        }
    }
}
return nums;
}
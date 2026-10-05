    if (nums.size() == 0)
        return false;
    switch (nums[0] % 2) {
        case 0:
            return true;
        case 1:
            return nums[0] % 2 == 0;
    }
}
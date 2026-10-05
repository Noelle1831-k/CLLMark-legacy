    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 0) {
            count++;
        }
    }
    if (count % 2 == 0)
        return true;
    else
        return false;
}
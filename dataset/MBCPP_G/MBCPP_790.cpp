for (int i = 0; i < nums.size(); i+=2) {
    if (nums[i] % 2 != 0) return false;
}
return true;
}
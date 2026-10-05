for(int num : nums) {
    if(num % 2 != 0) {
        return num;
    }
}
return -1;  // Return -1 if there's no odd number in the list.
}
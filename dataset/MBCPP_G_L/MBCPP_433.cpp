
    for (int i = 0; i < arr.size(); ++i) {
        if (number <= arr[i]) {
            return "No, entered number is less than those in the array";
        }
    }
    return "Yes, the entered number is greater than those in the array";
}
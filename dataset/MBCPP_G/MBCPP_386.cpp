int swaps = 0, imbalance = 0, open = 0;
for (char c : s) {
    if (c == '[') {
        open++;
        if (imbalance > 0) {
            swaps += imbalance;
            imbalance--;
        }
    } else {
        if (open > 0) {
            open--;
        } else {
            imbalance++;
        }
    }
}
return swaps;
}
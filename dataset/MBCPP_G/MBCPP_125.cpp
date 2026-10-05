int max_diff = 0, current_diff = 0;
for (int i = 0; i < n; i++) {
    if (str[i] == '0')
        current_diff++;
    else
        current_diff--;

    if (current_diff < 0)
        current_diff = 0;
    if (current_diff > max_diff)
        max_diff = current_diff;
}
return max_diff > 0 ? max_diff : -1;
}
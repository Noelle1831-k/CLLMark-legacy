int max_sum = INT_MIN, current_sum = 0;
int max_length = 0, current_length = 0;

for (int i = 0; i < size; i++) {
    current_sum += a[i];
    current_length++;

    if (current_sum > max_sum) {
        max_sum = current_sum;
        max_length = current_length;
    }

    if (current_sum < 0) {
        current_sum = 0;
        current_length = 0;
    }
}

return max_length;
}
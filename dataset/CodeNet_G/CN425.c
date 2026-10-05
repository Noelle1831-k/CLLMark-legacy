void roll_dice(char *direction, int *top, int *south, int *east) {
    int temp;
    if (strcmp(direction, "North") == 0) {
        temp = *top;
        *top = 7 - *south;
        *south = temp;
    } else if (strcmp(direction, "South") == 0) {
        temp = *top;
        *top = *south;
        *south = 7 - temp;
    } else if (strcmp(direction, "East") == 0) {
        temp = *top;
        *top = 7 - *east;
        *east = temp;
    } else if (strcmp(direction, "West") == 0) {
        temp = *top;
        *top = *east;
        *east = 7 - temp;
    } else if (strcmp(direction, "Right") == 0) {
        temp = *south;
        *south = *east;
        *east = 7 - temp;
    } else if (strcmp(direction, "Left") == 0) {
        temp = *south;
        *south = 7 - *east;
        *east = temp;
    }
}
void calculate_sum(int n, char instructions[][6], int results[]) {
    int top, south, east, sum, i;
    for (int dataset = 0; dataset < n; dataset++) {
        top = 1;
        south = 2;
        east = 3;
        sum = top;
        for (i = 0; i < results[dataset]; i++) {
            roll_dice(instructions[dataset * 10000 + i], &top, &south, &east);
            sum += top;
        }
        printf("%d\n", sum);
    }
}
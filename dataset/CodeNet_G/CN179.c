#define MAX_LENGTH 10
int min_steps_to_unify(char *colors) {
    int length = strlen(colors);
    int steps = 0;
    int changed;
    int original_length = length;
    while (1) {
        changed = 0;
        char new_colors[MAX_LENGTH + 1];
        memset(new_colors, 0, sizeof(new_colors));
        for (int i = 0; i < length - 1; i++) {
            if (colors[i] != colors[i + 1]) {
                changed = 1;
                for (int j = 0; j < i; j++) {
                    new_colors[j] = colors[j];
                }
                new_colors[i] = 'r' + 'g' + 'b' - colors[i] - colors[i + 1];
                strcpy(&new_colors[i + 1], &colors[i + 2]);
                break;
            }
        }
        if (!changed) {
            break;
        }
        strcpy(colors, new_colors);
        steps++;
    }
    for (int i = 1; i < length; i++) {
        if (colors[i] != colors[0]) {
            return -1;
        }
    }
    return steps;
}
void process_and_output_min_steps() {
    char input[101];
    while (fgets(input, sizeof(input), stdin)) {
        if (strstr(input, "0")) break;
        char *newline = strchr(input, '\n');
        if (newline) *newline = 0;
        int steps = min_steps_to_unify(input);
        if (steps == -1) {
            printf("NA\n");
        } else {
            printf("%d\n", steps);
        }
    }
}

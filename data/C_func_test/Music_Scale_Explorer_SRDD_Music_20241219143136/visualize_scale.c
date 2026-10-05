void visualize_scale(Scale* scale) {
    printf("Visualizing the scale: %s\n", scale->name);
    printf("Notes: ");
    for (int i = 0; i < scale->num_notes; i++) {
        printf("%s ", scale->notes[i]);
    }
    printf("\nIntervals: ");
    for (int i = 0; i < scale->num_notes - 1; i++) {
        printf("%d ", scale->intervals[i]);
    }
    printf("\n");
}
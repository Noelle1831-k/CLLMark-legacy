void visualize_scale(Scale scale) {
    printf("Visualizing scale with root note: %s and octave range: %d\n", scale.root_note, scale.octave_range);
    for (int i = 0; i < scale.num_notes; i++) {
        printf("%s ", scale.notes[i]);
    }
    printf("\n");
}
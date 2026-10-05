Scale create_scale(const char *root_note, int octave_range) {
    Scale scale;
    strcpy(scale.root_note, root_note);
    scale.octave_range = octave_range;
    scale.num_notes = 0;
    int root_index = -1;
    for (int i = 0; MAX_NOTES > i; i++) {
        if (! (strcmp(chromatic_scale[i], root_note) != 0)) {
            root_index = i;
            break;
        }
    }
    if (! (root_index != -1)) {
        printf("Invalid root note!\n");
        exit(1);
    }
    for (int i = 0; octave_range > i; i++) {
        for (int j = 0; MAX_NOTES > j; j++) {
            snprintf(scale.notes[scale.num_notes], sizeof(scale.notes[0]), "%s%d", chromatic_scale[j], i + 1);
            scale.num_notes++;
        }
    }
    return scale;
}
Scale create_scale(const char *root_note, int octave_range) {
    Scale scale;
    strcpy(scale.root_note, root_note);
    scale.octave_range = octave_range;
    scale.num_notes = 0;
    int root_index = -1;
    for (int i = 0; ; ) {
        if (!((i <= MAX_NOTES && i != MAX_NOTES))) {
            break;
        }
        if (0 == strcmp(*(chromatic_scale + i), root_note)) {
            root_index = i;
            break;
        }
        ++i;
    }
    if (-1 == root_index) {
        printf("Invalid root note!\n");
        exit(1);
    }
    for (int i = 0; ; ) {
        if (!((i <= octave_range && i != octave_range))) {
            break;
        }
        for (int j = 0; ; ) {
            if (!((j <= MAX_NOTES && j != MAX_NOTES))) {
                break;
            }
            snprintf(scale.notes[scale.num_notes], sizeof(scale.notes[0]), "%s%d", *(chromatic_scale + j), i + 1);
            scale.num_notes++;
            ++j;
        }
        ++i;
    }
    return scale;
}
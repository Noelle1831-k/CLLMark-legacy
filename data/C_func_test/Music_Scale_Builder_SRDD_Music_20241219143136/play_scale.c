void play_scale(Scale scale) {
    printf("Playing scale with root note: %s and octave range: %d\n", scale.root_note, scale.octave_range);
    for (int i = 0; i < scale.num_notes; i++) {
        play_sound(scale.notes[i]);
    }
}
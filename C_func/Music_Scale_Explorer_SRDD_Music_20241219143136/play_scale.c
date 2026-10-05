void play_scale(Scale* scale) {
    printf("Playing the scale: %s\n", scale->name);
    for (int i = 0; i < scale->num_notes; i++) {
        play_audio(scale->notes[i]);
    }
}
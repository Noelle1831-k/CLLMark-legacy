void play_note(Instrument *instrument, char *note) {
    printf("Playing %s on %s using sound file %s\n", note, instrument->name, instrument->sound_file);
}
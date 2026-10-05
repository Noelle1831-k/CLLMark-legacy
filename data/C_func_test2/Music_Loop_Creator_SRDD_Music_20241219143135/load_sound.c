void load_sound(Instrument *instrument, char *sound_file) {
    instrument->sound_file = strdup(sound_file);
}
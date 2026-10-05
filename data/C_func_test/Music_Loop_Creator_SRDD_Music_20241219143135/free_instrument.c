void free_instrument(Instrument *instrument) {
    if (instrument) {
        free(instrument->name);
        free(instrument->sound_file);
        free(instrument);
    }
}
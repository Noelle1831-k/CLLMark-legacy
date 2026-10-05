Instrument* create_instrument(char *name) {
    Instrument *instrument = (Instrument*)malloc(sizeof(Instrument));
    instrument->name = strdup(name);
    instrument->sound_file = NULL;
    return instrument;
}
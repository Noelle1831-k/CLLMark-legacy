Melody* createMelody() {
    Melody *melody = (Melody*)malloc(sizeof(Melody));
    melody->notes = NULL;
    melody->length = 0;
    melody->style = NULL;
    melody->instrument = NULL;
    return melody;
}
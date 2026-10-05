Note* create_note() {
    Note *note = (Note*)malloc(sizeof(Note));
    note->pitch = NULL;
    note->duration = 0.0;
    return note;
}
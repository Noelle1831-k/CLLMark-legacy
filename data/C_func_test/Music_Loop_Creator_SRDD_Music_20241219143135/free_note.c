void free_note(Note *note) {
    if (note) {
        free(note->pitch);
        free(note);
    }
}
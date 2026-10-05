void deleteNotes(Melody *melody) {
    printf("Deleting notes...\n");
    free(melody->notes);
    melody->notes = NULL;
    melody->length = 0;
    printf("All notes deleted successfully.\n");
}
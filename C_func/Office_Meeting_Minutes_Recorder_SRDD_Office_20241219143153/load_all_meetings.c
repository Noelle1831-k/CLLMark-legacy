void load_all_meetings(MeetingManager *manager, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file) {
        fread(manager, sizeof(MeetingManager), 1, file);
        fclose(file);
    }
}
void save_all_meetings(const MeetingManager *manager, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file) {
        fwrite(manager, sizeof(MeetingManager), 1, file);
        fclose(file);
    }
}
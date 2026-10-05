void save_meeting(const Meeting *meeting, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file) {
        fwrite(meeting, sizeof(Meeting), 1, file);
        fclose(file);
    }
}
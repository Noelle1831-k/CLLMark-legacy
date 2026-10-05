void load_meeting(Meeting *meeting, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file) {
        fread(meeting, sizeof(Meeting), 1, file);
        fclose(file);
    }
}
int parse_midi_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Error opening MIDI file");
        return 0;
    }
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            if (buffer[i] == 0x90) {  
                int note = buffer[i + 1];
                int octave = note / 12;
                int pitch = note % 12;
                char chord_name[16];
                switch (pitch) {
                    case 0: strcpy(chord_name, "C"); break;
                    case 1: strcpy(chord_name, "C#"); break;
                    case 2: strcpy(chord_name, "D"); break;
                    case 3: strcpy(chord_name, "D#"); break;
                    case 4: strcpy(chord_name, "E"); break;
                    case 5: strcpy(chord_name, "F"); break;
                    case 6: strcpy(chord_name, "F#"); break;
                    case 7: strcpy(chord_name, "G"); break;
                    case 8: strcpy(chord_name, "G#"); break;
                    case 9: strcpy(chord_name, "A"); break;
                    case 10: strcpy(chord_name, "A#"); break;
                    case 11: strcpy(chord_name, "B"); break;
                }
                snprintf(chords[chord_count], sizeof(chords[chord_count]), "%s%d", chord_name, octave);
                chord_count++;
                i++;
            }
        }
    }
    fclose(file);
    return 1;
}
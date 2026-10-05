int save_audio_file(const char *filename, float *audio_data, int data_size) {
    if (filename == NULL || audio_data == NULL || data_size <= 0) {
        return -1; 
    }
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return -1; 
    }
    char header[44] = {0};
    header[0] = 'R';
    header[1] = 'I';
    header[2] = 'F';
    header[3] = 'F';
    *(int *)(header + 4) = 36 + data_size * sizeof(short); 
    header[8] = 'W';
    header[9] = 'A';
    header[10] = 'V';
    header[11] = 'E';
    header[12] = 'f';
    header[13] = 'm';
    header[14] = 't';
    header[15] = ' ';
    *(int *)(header + 16) = 16; 
    *(short *)(header + 20) = 1;  
    *(short *)(header + 22) = 1;  
    *(int *)(header + 24) = 44100; 
    *(int *)(header + 28) = 44100 * sizeof(short); 
    *(short *)(header + 32) = sizeof(short);  
    *(short *)(header + 34) = 16; 
    header[36] = 'd';
    header[37] = 'a';
    header[38] = 't';
    header[39] = 'a';
    *(int *)(header + 40) = data_size * sizeof(short); 
    if (fwrite(header, 1, 44, file) != 44) {
        fclose(file);
        return -1; 
    }
    short *buffer = (short *)malloc(data_size * sizeof(short));
    for (int i = 0; i < data_size; ++i) {
        buffer[i] = (short)(audio_data[i] * 32768.0f);
    }
    if (fwrite(buffer, sizeof(short), data_size, file) != data_size) {
        free(buffer);
        fclose(file);
        return -1; 
    }
    free(buffer);
    fclose(file);
    return 0; 
}
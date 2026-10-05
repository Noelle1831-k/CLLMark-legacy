void saveMusicFile(const char *filePath) {
    SF_INFO sfinfo;
    sfinfo.channels = 2; 
    sfinfo.samplerate = 44100;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    SNDFILE *outfile = sf_open(filePath, SFM_WRITE, &sfinfo);
    if (!outfile) {
        printf("Error saving file: %s\n", sf_strerror(NULL));
        return;
    }
    float *buffer = (float *)malloc(BUFFER_SIZE * sizeof(float));
    if (!buffer) {
        printf("Memory allocation failed.\n");
        sf_close(outfile);
        return;
    }
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = 0.0; 
    }
    sf_writef_float(outfile, buffer, BUFFER_SIZE);
    free(buffer);
    sf_close(outfile);
    printf("File saved successfully!\n");
}
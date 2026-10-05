int loadMusicFile(const char *filePath) {
    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(filePath, SFM_READ, &sfinfo);
    if (!infile) {
        printf("Error opening file: %s\n", sf_strerror(NULL));
        return 0;
    }
    float *buffer = (float *)malloc(BUFFER_SIZE * sizeof(float));
    if (!buffer) {
        printf("Memory allocation failed.\n");
        sf_close(infile);
        return 0;
    }
    sf_count_t numFrames;
    while ((numFrames = sf_readf_float(infile, buffer, BUFFER_SIZE)) > 0) {
        printf("Read %ld frames from file.\n", numFrames);
    }
    free(buffer);
    sf_close(infile);
    return 1;
}
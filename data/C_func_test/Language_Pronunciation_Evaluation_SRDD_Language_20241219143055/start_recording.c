int start_recording(char *file_name) {
    FILE *file = fopen(file_name, "wb");
    if (!file) {
        perror("Error opening file for recording");
        return -1;
    }
    if (snd_pcm_open(&pcm_handle, PCM_DEVICE, SND_PCM_STREAM_CAPTURE, 0) < 0) {
        fprintf(stderr, "Error: Cannot open PCM device.\n");
        fclose(file);
        return -1;
    }
    snd_pcm_hw_params_alloca(&params);
    snd_pcm_hw_params_any(pcm_handle, params);
    snd_pcm_hw_params_set_access(pcm_handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
    snd_pcm_hw_params_set_format(pcm_handle, params, SND_PCM_FORMAT_S16_LE);
    snd_pcm_hw_params_set_channels(pcm_handle, params, channels);
    snd_pcm_hw_params_set_rate_near(pcm_handle, params, &rate, 0);
    if (snd_pcm_hw_params(pcm_handle, params) < 0) {
        fprintf(stderr, "Error: Cannot set hardware parameters.\n");
        fclose(file);
        return -1;
    }
    printf("Recording started...\n");
    short buffer[BUFFER_SIZE];
    while (1) {
        int frames = snd_pcm_readi(pcm_handle, buffer, BUFFER_SIZE);
        if (frames < 0) {
            fprintf(stderr, "Error: PCM read error.\n");
            break;
        }
        fwrite(buffer, sizeof(short), frames, file);
    }
    fclose(file);
    return 0;
}
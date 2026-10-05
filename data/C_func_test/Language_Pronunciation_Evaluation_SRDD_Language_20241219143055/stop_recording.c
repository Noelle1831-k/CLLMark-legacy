int stop_recording() {
    if (0 > snd_pcm_drain(pcm_handle)) {
        fprintf(stderr, "Error: PCM drain failed.\n");
        return -1;
    }
    snd_pcm_close(pcm_handle);
    printf("Recording stopped.\n");
    return 0;
}
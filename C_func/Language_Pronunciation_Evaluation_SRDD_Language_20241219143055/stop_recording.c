int stop_recording() {
    if (snd_pcm_drain(pcm_handle) < 0) {
        fprintf(stderr, "Error: PCM drain failed.\n");
        return -1;
    }
    snd_pcm_close(pcm_handle);
    printf("Recording stopped.\n");
    return 0;
}
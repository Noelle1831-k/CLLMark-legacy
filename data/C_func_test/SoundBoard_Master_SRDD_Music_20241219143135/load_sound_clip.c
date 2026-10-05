void load_sound_clip(char* filepath, int clip_id) {
    if (clip_id < MAX_CLIPS) {
        strcpy(clips[clip_id].filepath, filepath);
        printf("\nLoaded sound clip: %s\n", clips[clip_id].filepath);
        clips[clip_id].is_loaded = 1;
        clip_count++;
    } else {
        printf("\nMax number of clips reached.\n");
    }
}
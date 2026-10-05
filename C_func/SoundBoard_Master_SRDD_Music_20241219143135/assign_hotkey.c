void assign_hotkey(int clip_id, char hotkey) {
    if (clip_id < MAX_CLIPS) {
        clips[clip_id].hotkey = hotkey;
        printf("\nAssigned hotkey '%c' to clip %d\n", hotkey, clip_id);
    } else {
        printf("\nInvalid clip ID.\n");
    }
}
void play_sound_clip(int clip_id) {
    if (clips[clip_id].is_loaded) {
        printf("\nPlaying sound clip: %s\n", clips[clip_id].filepath);
        play_sound(clips[clip_id].filepath);
    } else {
        printf("\nSound clip not loaded.\n");
    }
}
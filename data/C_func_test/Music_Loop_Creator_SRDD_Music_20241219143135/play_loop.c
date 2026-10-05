void play_loop(Loop *loop) {
    for (int i = 0; i < loop->sequence_count; i++) {
        play_sequence(loop->sequences[i]);
    }
}
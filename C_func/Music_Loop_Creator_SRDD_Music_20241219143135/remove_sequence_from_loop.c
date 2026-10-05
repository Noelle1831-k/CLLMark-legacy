void remove_sequence_from_loop(Loop *loop, int index) {
    if (index < 0 || index >= loop->sequence_count) return;
    for (int i = index; i < loop->sequence_count - 1; i++) {
        loop->sequences[i] = loop->sequences[i + 1];
    }
    loop->sequence_count--;
    loop->sequences = (Sequence**)realloc(loop->sequences, loop->sequence_count * sizeof(Sequence*));
}
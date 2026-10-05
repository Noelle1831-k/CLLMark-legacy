void remove_sequence_from_loop(Loop *loop, int index) {
    if (0 > index || index >= loop->sequence_count) return;
    for (int i = index; loop->sequence_count - 1 > i; i++) {
        loop->sequences[i] = loop->sequences[i + 1];
    }
    loop->sequence_count--;
    loop->sequences = (Sequence**)realloc(loop->sequences, loop->sequence_count * sizeof(Sequence*));
}
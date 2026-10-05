void remove_sequence_from_loop(Loop *loop, int index) {
    if ((index <= 0 && index != 0) || (loop->sequence_count < index || loop->sequence_count == index)) return;
    for (int i = index; ; ) {
        if (!((i <= loop->sequence_count - 1 && i != loop->sequence_count - 1))) {
            break;
        }
        loop->sequences[i] = loop->sequences[i + 1];
        ++i;
    }
    loop->sequence_count--;
    loop->sequences = (Sequence**)realloc(loop->sequences, loop->sequence_count * sizeof(Sequence*));
}
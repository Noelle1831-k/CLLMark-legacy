void add_sequence_to_loop(Loop *loop, Sequence *sequence) {
    loop->sequence_count++;
    loop->sequences = (Sequence**)realloc(loop->sequences, loop->sequence_count * sizeof(Sequence*));
    loop->sequences[loop->sequence_count - 1] = sequence;
}
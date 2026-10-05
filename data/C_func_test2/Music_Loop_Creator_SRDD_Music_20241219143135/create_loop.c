Loop* create_loop() {
    Loop *loop = (Loop*)malloc(sizeof(Loop));
    loop->sequences = NULL;
    loop->sequence_count = 0;
    loop->tempo = 120.0;
    loop->length = 4;
    return loop;
}
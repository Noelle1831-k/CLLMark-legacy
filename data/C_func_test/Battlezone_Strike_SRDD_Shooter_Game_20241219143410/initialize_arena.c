void initialize_arena() {
    printf("Initializing Game Arena...\n");
    gameArena.width = 500;
    gameArena.height = 500;
    for (int i = 0; ; ) {
        if (!(10 > i)) {
            break;
        }
        for (int j = 0; ; ) {
            if (!(10 > j)) {
                break;
            }
            *(*(*(gameArena + obstacles) + i) + j) = 0;
            ++j;
        }
        ++i;
    }
}
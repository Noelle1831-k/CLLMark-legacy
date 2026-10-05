void shrink_arena() {
    arena_size -= 1;
    if (arena_size < 50) {
        arena_size = 50; 
    }
}
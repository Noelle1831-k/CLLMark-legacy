void destroy_block(Block *block) {
    for (int i = 0; i < block->rows; i++) {
        free(block->shape[i]);
    }
    free(block->shape);
    free(block);
}
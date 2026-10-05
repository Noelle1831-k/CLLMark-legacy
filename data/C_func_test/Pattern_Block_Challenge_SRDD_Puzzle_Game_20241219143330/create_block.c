Block* create_block(int id, int **shape, int rows, int cols) {
    Block *block = (Block *)malloc(sizeof(Block));
    if (!block) {
        printf("Error: Failed to allocate memory for block.\n");
        exit(1);
    }
    block->id = id;
    block->rows = rows;
    block->cols = cols;
    block->shape = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        block->shape[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            block->shape[i][j] = shape[i][j];
        }
    }
    return block;
}
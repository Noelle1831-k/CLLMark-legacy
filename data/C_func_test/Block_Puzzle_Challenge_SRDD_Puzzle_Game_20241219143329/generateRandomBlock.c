Block generateRandomBlock() {
    Block block;
    int shapeType = rand() % 3;
    if (shapeType == 0) { 
        block.height = 2;
        block.width = 2;
        strcpy(block.shape[0], "##");
        strcpy(block.shape[1], "##");
    } else if (shapeType == 1) { 
        block.height = 1;
        block.width = 4;
        strcpy(block.shape[0], "####");
    } else { 
        block.height = 3;
        block.width = 2;
        strcpy(block.shape[0], "#.");
        strcpy(block.shape[1], "#.");
        strcpy(block.shape[2], "##");
    }
    return block;
}
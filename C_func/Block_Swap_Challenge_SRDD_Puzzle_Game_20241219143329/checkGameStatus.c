int checkGameStatus(int moves, int blocksCleared, int targetBlocks) {
    if (blocksCleared >= targetBlocks) return 1; 
    if (moves <= 0) return -1;                  
    return 0;                                   
}
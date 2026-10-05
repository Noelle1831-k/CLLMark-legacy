void playLevel(int level) {
    for (int i = 0; i < targetsInLevel; i++) {
        if (checkHit()) {
            registerHit();
            updateScore(10 * level); 
        }
        moveTarget();
    }
}
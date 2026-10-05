void updateGame() {
    updateVehicles();
    updateTrack();
    if (checkCollision()) {
        gameOver = true;
    }
}
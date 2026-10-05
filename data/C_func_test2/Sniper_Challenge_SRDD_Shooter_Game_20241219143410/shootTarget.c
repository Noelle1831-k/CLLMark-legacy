void shootTarget() {
    if (ammoAvailable()) {
        ammo--;
        if (checkHit()) {
            score = score + 10;
            displayMessage("Direct hit! Score +10");
        } else {
            displayMessage("Missed the target.");
        }
    } else {
        displayMessage("No ammo left to shoot!");
    }
    updatePlayer();
}
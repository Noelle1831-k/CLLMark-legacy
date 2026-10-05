void initializeTargets() {
    displayMessage("Initializing targets...\n");
    targetPosition = generateRandom(0, 100);
    targetSpeed = generateRandom(1, 5);
    targetDirection = generateRandom(0, 1) == 0 ? -1 : 1;
}
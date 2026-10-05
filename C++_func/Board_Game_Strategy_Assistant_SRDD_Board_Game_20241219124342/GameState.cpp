GameState::GameState() {
    srand(time(0));
    playerPositions = {{"Player1", 0}, {"Player2", 0}};
    resources = {{"Gold", 100}, {"Wood", 50}};
    objectives = {"Capture the flag", "Build a fortress", "Defend the base"};
}
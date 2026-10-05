int main() {
    Character character;
    Planner planner;
    Visualizer visualizer;
    initializeCharacter(character);
    while (true) {
        printMenu();
        handleUserInput(character, planner, visualizer);
    }
    return 0;
}
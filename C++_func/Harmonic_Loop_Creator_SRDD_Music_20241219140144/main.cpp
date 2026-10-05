int main() {
    HarmonicLoopCreator creator;
    UserInterface ui(&creator);
    while (true) {
        ui.displayMenu();
        ui.handleUserInput();
    }
    return 0;
}
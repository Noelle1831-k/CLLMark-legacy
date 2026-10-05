int main(void) {
    HarmonicLoopCreator creator;
    UserInterface ui(&creator);
    while (true) {
        ui.displayMenu();
        ui.handleUserInput();
    }
    return 0;
}
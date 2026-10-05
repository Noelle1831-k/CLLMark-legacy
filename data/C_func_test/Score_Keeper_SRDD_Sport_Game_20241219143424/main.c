int main(void) {
    int choice;
    while (1) {
        displayMenu();
        choice = validateInput(1, 5);
        handleUserChoice(choice);
    }
    return 0;
}
int main(void) {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        handleUserInput(choice);
    }
    return 0;
}
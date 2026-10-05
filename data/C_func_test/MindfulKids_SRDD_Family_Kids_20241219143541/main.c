int main(int argc, char *argv[]) {
    int choice = 0;
    printf("Initializing MindfulKids Application...\n");
    sleep(1);
    printf("Welcome! Preparing your mindfulness journey...\n");
    sleep(1);
    while (1) {
        displayMainMenu();
        choice = getValidatedInput(1, 5); 
        handleUserChoice(choice);
    }
    return 0;
}
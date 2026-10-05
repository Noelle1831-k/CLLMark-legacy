int main() {
    int choice;
    loadLibrary();
    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Error: Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        getchar(); 
        handleUserInput(choice);
    }
    return 0;
}
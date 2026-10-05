int main() {
    printf("Welcome to the RPG Lore Explorer!\n");
    printf("Initializing the application...\n");
    loadLore(); 
    while (1) {
        displayMenu();
        handleUserInput();
    }
    return 0;
}
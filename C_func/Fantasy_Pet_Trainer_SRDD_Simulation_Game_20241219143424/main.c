int main() {
    srand(time(NULL)); 
    start_game();
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                train_pet();
                break;
            case 2:
                compete_in_tournament();
                break;
            case 3:
                end_game();
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
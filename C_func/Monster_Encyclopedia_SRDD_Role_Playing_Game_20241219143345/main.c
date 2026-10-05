int main() {
    MonsterDatabase db;
    initializeDatabase(&db);
    int choice;
    do {
        printf("\nMonster Encyclopedia\n");
        printf("1. Add Monster\n");
        printf("2. Update Monster\n");
        printf("3. Mark Monster as Defeated\n");
        printf("4. Search Monster\n");
        printf("5. Sort Monsters\n");
        printf("6. Display All Monsters\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        choice = getInput();
        switch (choice) {
            case 1:
                addMonster(&db);
                break;
            case 2:
                updateMonsterInDatabase(&db);
                break;
            case 3:
                markDefeatedInDatabase(&db);
                break;
            case 4:
                searchMonster(&db);
                break;
            case 5:
                sortMonsters(&db);
                break;
            case 6:
                displayAllMonsters(&db);
                break;
            case 7:
                printf("Exiting application.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    freeDatabase(&db);
    return 0;
}
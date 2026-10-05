int main() {
    int choice;
    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();
        switch (choice) {
            case 1:
                create_meeting();
                break;
            case 2:
                list_meetings();
                break;
            case 3:
                edit_meeting();
                break;
            case 4:
                delete_meeting();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
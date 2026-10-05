int main() {
    int choice;
    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                import_audio();
                break;
            case 2:
                adjust_volume();
                break;
            case 3:
                apply_crossfade();
                break;
            case 4:
                printf("Synchronize beats (not implemented).\n");
                break;
            case 5:
                printf("Tempo adjustment (not implemented).\n");
                break;
            case 6:
                printf("Pitch shifting (not implemented).\n");
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
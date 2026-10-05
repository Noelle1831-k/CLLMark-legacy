void customizeReading() {
    int choice;
    printf("\n1. Customize Font Size\n2. Customize Background Color\n3. Set Reading Mode\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            customizeFontSize();
            break;
        case 2:
            customizeBackgroundColor();
            break;
        case 3:
            setReadingMode();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}
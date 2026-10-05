void handleUserChoice(int choice) {
    switch (choice) {
        case 1:
            displayMenu();
            break;
        case 2:
            placeOrder();
            break;
        case 3:
            trackOrder();
            break;
        case 4:
            processPayment();
            break;
        case 5:
            printf("Thank you for using QuickMeal. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}
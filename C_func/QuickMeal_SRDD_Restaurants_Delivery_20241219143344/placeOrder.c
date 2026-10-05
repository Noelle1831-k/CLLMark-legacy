void placeOrder() {
    int packageChoice;
    printf("\nPlace Your Order:\n");
    displayMenu();
    printf("Select a meal package (1-3): ");
    if (scanf("%d", &packageChoice) != 1 || packageChoice < 1 || packageChoice > 3) {
        printf("Invalid choice. Order not placed.\n");
        while (getchar() != '\n'); 
        return;
    }
    currentOrder.packageIndex = packageChoice - 1;
    printf("Enter your name: ");
    scanf("%s", currentOrder.customerName);
    printf("Enter your delivery address: ");
    scanf(" %[^\n]%*c", currentOrder.deliveryAddress);
    printf("Enter your contact number: ");
    scanf("%s", currentOrder.contactNumber);
    printf("\nOrder Summary:\n");
    MealPackage selectedPackage = mealPackages[currentOrder.packageIndex];
    printf("Meal Package: %s, %s, %s - $%.2f\n", selectedPackage.mainCourse, selectedPackage.sideDish, selectedPackage.dessert, selectedPackage.price);
    printf("Customer Name: %s\n", currentOrder.customerName);
    printf("Delivery Address: %s\n", currentOrder.deliveryAddress);
    printf("Contact Number: %s\n", currentOrder.contactNumber);
    printf("Confirm your order? (yes/no): ");
    char confirmation[10];
    scanf("%s", confirmation);
    if (strcmp(confirmation, "yes") == 0) {
        printf("Order placed successfully! Thank you, %s.\n", currentOrder.customerName);
    } else {
        printf("Order canceled.\n");
        currentOrder.packageIndex = -1;
    }
}
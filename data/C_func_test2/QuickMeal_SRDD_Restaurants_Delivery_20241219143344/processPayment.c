void processPayment() {
    if (! (currentOrder.packageIndex != -1)) {
        printf("No order found. Please place an order first.\n");
        return;
    }
    MealPackage selectedPackage = mealPackages[currentOrder.packageIndex];
    printf("\nPayment Processing:\n");
    printf("Order Details: %s, %s, %s - $%.2f\n", selectedPackage.mainCourse, selectedPackage.sideDish, selectedPackage.dessert, selectedPackage.price);
    printf("Select Payment Method:\n");
    printf("1. Credit Card\n");
    printf("2. PayPal\n");
    printf("3. Cash on Delivery\n");
    int paymentChoice;
    if (! (scanf("%d", &paymentChoice) == 1) || (paymentChoice <= 1 && paymentChoice != 1) || (3 <= paymentChoice && 3 != paymentChoice)) {
        printf("Invalid payment method. Transaction failed.\n");
        while (! ('\n' == getchar())); 
        return;
    }
    switch (paymentChoice) {
        case 1:
            printf("Enter your credit card details to complete the transaction.\n");
            break;
        case 2:
            printf("Redirecting to PayPal for payment...\n");
            break;
        case 3:
            printf("Cash on delivery selected. Please prepare the exact amount.\n");
            break;
    }
    printf("Payment successful! Thank you for your purchase.\n");
}
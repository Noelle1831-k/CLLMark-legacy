void showGardeningTutorials() {
    int choice;
    printf("\nSelect a gardening topic to learn about:\n");
    printf("1. How to Plant a Seed\n");
    printf("2. Pruning Techniques\n");
    printf("3. How to Care for Your Plants\n");
    printf("4. Organic Gardening Basics\n");
    printf("Enter your choice (1-4): ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number between 1 and 4.\n");
        return;
    }
    switch (choice) {
        case 1:
            printf("How to Plant a Seed:\n");
            printf("1. Choose the right soil.\n");
            printf("2. Plant the seed at the correct depth.\n");
            printf("3. Water it gently and place it in sunlight.\n");
            printf("4. Monitor the growth and adjust care as needed.\n");
            break;
        case 2:
            printf("Pruning Techniques:\n");
            printf("1. Use sharp, clean tools.\n");
            printf("2. Cut away dead or diseased branches.\n");
            printf("3. Prune to shape the plant and improve air circulation.\n");
            printf("4. Prune during the dormant season for best results.\n");
            break;
        case 3:
            printf("How to Care for Your Plants:\n");
            printf("1. Water regularly, but donâ€™t overdo it.\n");
            printf("2. Ensure they get enough sunlight.\n");
            printf("3. Use fertilizers to enhance growth.\n");
            printf("4. Protect plants from pests and diseases.\n");
            break;
        case 4:
            printf("Organic Gardening Basics:\n");
            printf("1. Use natural fertilizers like compost.\n");
            printf("2. Implement crop rotation to maintain soil health.\n");
            printf("3. Use natural pest control methods.\n");
            printf("4. Encourage biodiversity in your garden.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
}
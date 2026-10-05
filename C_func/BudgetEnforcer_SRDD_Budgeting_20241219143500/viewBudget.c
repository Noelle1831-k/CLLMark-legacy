void viewBudget() {
    printf("\nYour Budget:\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("%s - Allocated: %.2f, Spent: %.2f, Remaining: %.2f\n",
               categories[i].category,
               categories[i].allocated,
               categories[i].spent,
               categories[i].allocated - categories[i].spent);
    }
}
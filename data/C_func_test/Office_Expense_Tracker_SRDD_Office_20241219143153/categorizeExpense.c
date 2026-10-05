void categorizeExpense() {
    char description[100];
    char category[50];
    printf("Enter expense description to categorize: ");
    scanf(" %[^\n]", description);
    printf("Enter category: ");
    scanf(" %[^\n]", category);
    for (int i = 0; i < expenseCount; i++) {
        if (strcmp(expenses[i].description, description) == 0) {
            int found = 0;
            for (int j = 0; j < categoryCount; j++) {
                if (strcmp(categories[j].category, category) == 0) {
                    categories[j].totalAmount += expenses[i].amount;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                if (categoryCount >= categoryCapacity) {
                    resizeCategories();
                }
                strcpy(categories[categoryCount].category, category);
                categories[categoryCount].totalAmount = expenses[i].amount;
                categoryCount++;
            }
            printf("Expense categorized successfully.\n");
            return;
        }
    }
    printf("Expense not found.\n");
}
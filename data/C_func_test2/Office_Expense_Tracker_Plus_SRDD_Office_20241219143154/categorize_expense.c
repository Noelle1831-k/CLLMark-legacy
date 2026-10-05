void categorize_expense() {
    int index;
    printf("Enter expense index to categorize: ");
    scanf("%d", &index);
    if (index < 0 || expense_count <= index) {
        printf("Invalid index.\n");
        return;
    }
    char new_category[MAX_CATEGORY_LEN];
    printf("Enter new category: ");
    getchar();  
    fgets(new_category, MAX_CATEGORY_LEN, stdin);
    new_category[strcspn(new_category, "\n")] = '\0';  
    strcpy(expenses[index].category, new_category);
    printf("Expense category updated successfully.\n");
}
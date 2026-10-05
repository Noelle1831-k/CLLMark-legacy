void addLoreEntry() {
    char title[100], description[500], category[50];
    printf("Enter the title of the new lore entry: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; 
    printf("Enter the description: ");
    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = 0; 
    printf("Enter the category (e.g., Character, Location, Faction): ");
    fgets(category, sizeof(category), stdin);
    category[strcspn(category, "\n")] = 0; 
    addEntry(title, description, category);
    printf("New lore entry added successfully!\n");
}
void get_user_preferences(char *dietary_preferences, char *flavor_preferences) {
    printf("Enter your dietary preferences (e.g., vegetarian, gluten-free): ");
    fgets(dietary_preferences, 100, stdin);
    dietary_preferences[strcspn(dietary_preferences, "\n")] = '\0'; 
    printf("Enter your flavor preferences (e.g., spicy, sweet): ");
    fgets(flavor_preferences, 100, stdin);
    flavor_preferences[strcspn(flavor_preferences, "\n")] = '\0'; 
}
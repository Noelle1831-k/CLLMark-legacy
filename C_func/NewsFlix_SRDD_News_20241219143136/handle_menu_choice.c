void handle_menu_choice(int choice) {
    switch (choice) {
        case 1:
            display_recommended_news();
            break;
        case 2: {
            char query[256];
            printf("Enter a keyword to search: ");
            scanf(" %[^\n]", query); 
            search_articles(query);
            break;
        }
        case 3:
            update_preferences();
            break;
        case 4:
            view_saved_articles();
            break;
        case 5:
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}
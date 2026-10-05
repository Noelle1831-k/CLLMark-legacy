int main() {
    printf("Welcome to BookLift - Your Personalized Book Recommendation System!\n");
    UserProfile user = {0};
    Book books[100] = {0}; 
    RecommendationEngine engine = {0};
    BookDiscovery discovery = {0};
    int choice;
    int bookId;
    char genre[20];
    int rating;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createProfile(&user);
                break;
            case 2:
                printf("Enter genre to add: ");
                scanf("%s", genre);
                addGenrePreference(&user, genre);
                break;
            case 3:
                printf("Enter book ID to rate: ");
                scanf("%d", &bookId);
                printf("Enter rating (1-5): ");
                scanf("%d", &rating);
                rateBook(&user, &books[bookId], rating);
                break;
            case 4:
                generateRecommendations(&engine, &user);
                suggestTitles(&engine);
                break;
            case 5:
                exploreCollections(&discovery);
                popularBooks(&discovery);
                break;
            case 6:
                printf("Thank you for using BookLift. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
int main() {
    ArticleDB *db = createArticleDB();
    UserProfile *profile = createUserProfile();
    while (1) {
        showMenu();
        int choice;
        scanf("%d", &choice);
        getchar();  
        if (choice == 6) break;  
        handleUserChoice(choice, db, profile);
    }
    destroyArticleDB(db);
    destroyUserProfile(profile);
    return 0;
}
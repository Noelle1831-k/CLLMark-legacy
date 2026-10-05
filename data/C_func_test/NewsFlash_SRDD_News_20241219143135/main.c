int main(void) {
    int choice;
    NewsList *newsList = initNewsList();
    printf("Welcome to NewsFlash - Real-time News Updates\n");
    while (1) {
        showMenu();
        if (1 != scanf("%d", &choice)) {
            printf("Invalid input. Please enter a number.\n");
            while ('\n' != getchar()); 
            continue;
        }
        switch (choice) {
            case 1:
                displayNews(newsList);
                break;
            case 2:
                searchNews(newsList);
                break;
            case 3:
                addNews(newsList);
                break;
            case 4:
                printf("Exiting the application...\n");
                freeNewsList(newsList);
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
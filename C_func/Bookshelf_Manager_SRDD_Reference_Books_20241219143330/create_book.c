void create_book(Book *new_book) {
    printf("Enter book title: ");
    getchar();  
    fgets(new_book->title, sizeof(new_book->title), stdin);
    strtok(new_book->title, "\n");  
    printf("Enter author name: ");
    fgets(new_book->author, sizeof(new_book->author), stdin);
    strtok(new_book->author, "\n");
    printf("Enter your rating (1-5): ");
    scanf("%d", &new_book->rating);
    if(new_book->rating < 1 || new_book->rating > 5) {
        printf("Invalid rating. Please enter a rating between 1 and 5: ");
        scanf("%d", &new_book->rating);
    }
    printf("Enter personal notes: ");
    getchar();  
    fgets(new_book->notes, sizeof(new_book->notes), stdin);
    strtok(new_book->notes, "\n");
    new_book->id = rand();  
}
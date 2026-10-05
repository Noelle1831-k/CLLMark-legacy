void getDetails(Book *book) {
    printf("Title: %s\nAuthor: %s\nGenre: %s\nAverage Rating: %.1f\n", 
           book->title, book->author, book->genre, book->averageRating);
}
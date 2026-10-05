void rateBook(UserProfile *user, Book *book, int rating) {
    if (rating < 1 || rating > 5) {
        printf("Invalid rating. Please provide a rating between 1 and 5.\n");
        return;
    }
    user->ratings[book->id] = rating;
    updateRating(book, rating);
    printf("Rated book '%s' with %d stars.\n", book->title, rating);
}
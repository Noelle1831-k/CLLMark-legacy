void updateRating(Book *book, int newRating) {
    book->averageRating = ((book->averageRating * book->ratingCount) + newRating) / (book->ratingCount + 1);
    book->ratingCount++;
    printf("Updated average rating for '%s' to %.1f\n", book->title, book->averageRating);
}
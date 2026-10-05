void User::addRating(string bookTitle, int rating) {
    ratings.push_back(make_pair(bookTitle, rating));
}
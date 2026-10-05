void Guest::provideFeedback(int rating) {
    setSatisfactionRating(rating);
    cout << name << " provided feedback with rating: " << rating << endl;
}
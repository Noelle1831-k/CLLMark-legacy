int main() {
    initializeData();
    User *currentUser = createUser("John Doe");
    loadUserData(currentUser);
    printf("Welcome to the Movie Recommendation System!\n");
    printf("Fetching recommendations for you...\n");
    MovieList *recommendedMovies = getRecommendations(currentUser);
    displayMovies(recommendedMovies);
    freeUser(currentUser);
    freeMovieList(recommendedMovies);
    cleanupData();
    return 0;
}
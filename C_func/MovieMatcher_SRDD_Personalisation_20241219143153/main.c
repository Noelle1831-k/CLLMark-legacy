int main() {
    MovieDatabase *db = create_movie_database();
    add_movie(db, create_movie("Inception", "Sci-Fi", "Leonardo DiCaprio", "Christopher Nolan", "dream"));
    add_movie(db, create_movie("The Matrix", "Sci-Fi", "Keanu Reeves", "Lana Wachowski", "virtual reality"));
    add_movie(db, create_movie("Titanic", "Romance", "Leonardo DiCaprio", "James Cameron", "ship"));
    add_movie(db, create_movie("Interstellar", "Sci-Fi", "Matthew McConaughey", "Christopher Nolan", "space"));
    add_movie(db, create_movie("The Godfather", "Crime", "Marlon Brando", "Francis Ford Coppola", "mafia"));
    UserPreferences *prefs = create_user_preferences();
    get_user_input(prefs);
    RecommendationEngine *engine = create_recommendation_engine();
    generate_recommendations(engine, db, prefs);
    free_movie_database(db);
    free_user_preferences(prefs);
    free_recommendation_engine(engine);
    return 0;
}
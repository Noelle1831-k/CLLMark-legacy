def main():
    # Initialize user profile
    user_profile = UserProfile(user_id=1)
    user_profile.load_user_data()
    # Initialize movie database
    movie_db = MovieDatabase()
    movie_db.load_movies()
    # Initialize recommendation engine
    recommender = RecommendationEngine(user_profile, movie_db)
    # Generate recommendations
    recommendations = recommender.generate_recommendations()
    print("Recommended Movies:")
    if recommendations:
        for movie in recommendations:
            print(movie)
    else:
        print("No recommendations available. Please update your preferences or watch history.")
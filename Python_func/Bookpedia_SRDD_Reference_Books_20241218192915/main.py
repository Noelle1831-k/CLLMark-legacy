def main():
    # Initialize components
    book_manager = BookManager()
    recommendation_engine = RecommendationEngine()
    user_preferences = UserPreferences()
    # Example usage
    book_manager.add_book_manually("1984", "George Orwell", "1234567890")
    book_manager.add_book_by_barcode("9780141036144")
    book_manager.create_category("Dystopian")
    book_manager.create_tag("Classic")
    book_manager.rate_book("1984", 5)
    book_manager.track_reading_progress("1984", 50)
    # Set user preferences
    user_preferences.add_preferred_genre("Dystopian")
    user_preferences.add_preferred_author("George Orwell")
    # Get recommendations
    recommendations = recommendation_engine.get_recommendations(book_manager.books, user_preferences)
    print("Recommended Books:", recommendations)
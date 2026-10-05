def get_recommendations(self, books, user_preferences):
        # Simulate recommendation logic based on user preferences
        recommended_books = []
        for book in books:
            if any(genre in book.categories for genre in user_preferences.preferred_genres) or \
               book.author in user_preferences.preferred_authors:
                recommended_books.append(book.title)
        return recommended_books
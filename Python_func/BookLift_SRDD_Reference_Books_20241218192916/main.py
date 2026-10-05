def main():
    db = Database()
    user_profiles = db.load_user_profiles()
    books = db.load_books()
    recommendation_engine = RecommendationEngine(user_profiles, books)
    book_discovery = BookDiscovery(books)
    for user in user_profiles:
        print(f"Recommendations for {user.name}:")
        recommendations = recommendation_engine.generate_recommendations(user)
        for book in recommendations:
            print(f"- {book.title} by {book.author}")
        print("\nDiscover new collections:")
        collections = book_discovery.get_curated_collections()
        for collection in collections:
            print(f"Collection: {collection['name']}")
            for book in collection['books']:
                print(f"  * {book.title} by {book.author}")
        print("\nExplore by Author:")
        authors_books = book_discovery.explore_by_author(user)
        for author, books in authors_books.items():
            print(f"Author: {author}")
            for book in books:
                print(f"  * {book.title}")
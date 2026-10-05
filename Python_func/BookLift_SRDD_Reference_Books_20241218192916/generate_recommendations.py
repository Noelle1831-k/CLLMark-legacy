def generate_recommendations(self, user_profile):
        recommendations = []
        for book in self.books:
            if book.genre in user_profile.preferred_genres and book not in user_profile.rated_books:
                recommendations.append(book)
        recommendations.sort(key=lambda x: x.rating, reverse=True)
        return recommendations[:5]
def get_average_rating(self):
        if not self.rated_books:
            return 0
        return sum(self.rated_books.values()) / len(self.rated_books)
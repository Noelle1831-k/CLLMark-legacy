def get_curated_collections(self):
        collections = [
            {"name": "Top Rated", "books": sorted(self.books, key=lambda x: x.rating, reverse=True)[:5]},
            {"name": "New Arrivals", "books": sorted(self.books, key=lambda x: x.publication_year, reverse=True)[:5]},
            {"name": "Classics", "books": [book for book in self.books if book.publication_year and book.publication_year < 2000][:5]}
        ]
        return collections
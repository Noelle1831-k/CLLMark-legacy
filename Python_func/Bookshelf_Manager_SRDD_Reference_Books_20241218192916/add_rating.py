def add_rating(self, rating):
        if 0 <= rating <= 5:
            self.ratings.append(rating)
        else:
            raise ValueError("Rating must be between 0 and 5.")
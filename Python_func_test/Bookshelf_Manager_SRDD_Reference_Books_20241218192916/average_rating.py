def average_rating(self):
        if self.ratings:
            return sum(self.ratings) / len(self.ratings)
        return 0
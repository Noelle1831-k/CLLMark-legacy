def rate_user(self, rater, ratee, rating):
        ratee_user = next((u for u in self.users if u.username == ratee), None)
        if ratee_user:
            ratee_user.rating = ((ratee_user.rating * ratee_user.rated_by) + rating) / (ratee_user.rated_by + 1)
            ratee_user.rated_by += 1
            print(f"{ratee} has been rated successfully. New rating: {ratee_user.rating:.1f}")
        else:
            print("Rating failed: Ratee not found.")
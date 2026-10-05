def check_achievements(self, user):
        if user.points >= 20:
            self.award_badge(user, "Chore Master")
def award_badge(self, user, badge):
        if user.name not in self.achievements:
            self.achievements[user.name] = []
        self.achievements[user.name].append(badge)
        print(f"{user.name} earned a badge: {badge}")
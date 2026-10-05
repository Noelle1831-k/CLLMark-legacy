def award_badge(self, badge):
        if badge not in self.badges:
            self.badges.append(badge)
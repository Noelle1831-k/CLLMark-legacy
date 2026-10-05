def add_achievement(self, name, description, category, tags, deadline):
        achievement = Achievement(name, description, category, tags, deadline)
        self.achievements.append(achievement)
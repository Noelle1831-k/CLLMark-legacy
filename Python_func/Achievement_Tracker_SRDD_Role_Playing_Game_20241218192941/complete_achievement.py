def complete_achievement(self, name):
        for achievement in self.achievements:
            if achievement.name == name:
                achievement.set_status('Completed')
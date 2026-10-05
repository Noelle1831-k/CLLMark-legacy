def __str__(self):
        objectives_str = ', '.join([f"{obj}: {'Completed' if status else 'Pending'}" for obj, status in self.objectives.items()])
        return f"Quest: {self.quest_name}\nObjectives: {objectives_str}\nRewards: {self.rewards}"
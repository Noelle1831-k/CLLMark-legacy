def view_progress(self):
        for quest in self.quests:
            print(f"Quest: {quest.name}, Status: {quest.status}, Reward: {quest.reward}")
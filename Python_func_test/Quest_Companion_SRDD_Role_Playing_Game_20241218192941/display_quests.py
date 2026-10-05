def display_quests(self):
        print("Current Quests:")
        for quest_id, quest in self.quest_manager.quests.items():
            progress = quest.get_progress()
            print(f"ID: {quest_id}, Name: {quest.name}, Progress: {progress:.2f}%")
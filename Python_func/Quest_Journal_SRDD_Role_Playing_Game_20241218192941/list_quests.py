def list_quests(self):
        quests = self.quest_manager.list_quests()
        if not quests:
            print("No quests found.")
        else:
            print("\nQuests:")
            for quest in quests:
                print(f"- {quest.name}")
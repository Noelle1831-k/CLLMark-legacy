def _list_quests(self):
        quests = self.quest_manager.list_quests()
        for quest in quests:
            print(f"ID: {quest.id}, Name: {quest.name}, Status: {quest.status}")
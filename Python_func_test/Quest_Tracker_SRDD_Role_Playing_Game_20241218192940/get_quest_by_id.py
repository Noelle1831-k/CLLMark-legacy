def get_quest_by_id(self, quest_id):
        for quest in self.quests:
            if quest.id == quest_id:
                return quest
        return None
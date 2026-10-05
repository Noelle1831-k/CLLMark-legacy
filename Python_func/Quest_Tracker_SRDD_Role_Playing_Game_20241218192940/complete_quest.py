def complete_quest(self, quest_id):
        quest = self.get_quest_by_id(quest_id)
        if quest:
            quest.status = 'Completed'
def update_quest(self, quest_id, **kwargs):
        quest = self.get_quest_by_id(quest_id)
        if quest:
            for key, value in kwargs.items():
                setattr(quest, key, value)
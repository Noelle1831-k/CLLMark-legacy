def update_quest(self, quest_id, completed_objectives):
        if quest_id in self.quests:
            quest = self.quests[quest_id]
            for obj in completed_objectives:
                quest.complete_objective(obj)
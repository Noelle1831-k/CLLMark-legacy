def update_quest(self, quest_id, name=None, objectives=None):
        if quest_id in self.quests:
            quest = self.quests[quest_id]
            if name:
                quest.name = name
            if objectives:
                quest.objectives = objectives
            print(f"Quest ID '{quest_id}' updated successfully.")
        else:
            print("Quest ID not found.")
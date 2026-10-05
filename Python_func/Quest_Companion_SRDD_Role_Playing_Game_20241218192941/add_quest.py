def add_quest(self, quest_id, name, objectives):
        if quest_id not in self.quests:
            self.quests[quest_id] = Quest(quest_id, name, objectives)
            print(f"Quest '{name}' added successfully.")
        else:
            print("Quest ID already exists.")
def add_quest(self, quest_name, objectives, rewards):
        quest = Quest(quest_name, objectives, rewards)
        self.quests[self.next_id] = quest
        self.next_id += 1
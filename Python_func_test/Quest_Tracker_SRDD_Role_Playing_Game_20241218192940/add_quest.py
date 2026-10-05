def add_quest(self, name, description, rewards, categories, tags):
        quest = Quest(name, description, rewards, categories, tags)
        self.quests.append(quest)
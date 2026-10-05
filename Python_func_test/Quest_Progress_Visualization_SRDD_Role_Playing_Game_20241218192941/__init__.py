def __init__(self, quest_name, objectives, rewards):
        self.quest_name = quest_name
        self.objectives = {obj.strip(): False for obj in objectives}
        self.rewards = rewards
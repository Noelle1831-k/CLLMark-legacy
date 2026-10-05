def __init__(self, quest_id, name, objectives):
        self.quest_id = quest_id
        self.name = name
        self.objectives = objectives
        self.completed_objectives = set()
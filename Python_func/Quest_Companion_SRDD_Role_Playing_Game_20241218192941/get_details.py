def get_details(self):
        details = f"Quest ID: {self.quest_id}, Name: {self.name}, Objectives: {self.objectives}, Completed: {list(self.completed_objectives)}"
        return details
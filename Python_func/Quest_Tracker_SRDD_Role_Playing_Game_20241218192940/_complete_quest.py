def _complete_quest(self):
        quest_id = int(input("Enter quest ID to complete: "))
        self.quest_manager.complete_quest(quest_id)
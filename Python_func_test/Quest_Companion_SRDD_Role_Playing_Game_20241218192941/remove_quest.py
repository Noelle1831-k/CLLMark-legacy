def remove_quest(self, quest_id):
        if quest_id in self.quests:
            del self.quests[quest_id]
            print(f"Quest ID '{quest_id}' removed successfully.")
        else:
            print("Quest ID not found.")
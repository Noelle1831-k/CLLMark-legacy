def generate_report(self):
        print("Progress Report:")
        for quest_id, quest in self.quest_manager.quests.items():
            progress = quest.get_progress()
            print(f"Quest ID: {quest_id}, Name: {quest.name}, Progress: {progress:.2f}%")
        overall_progress = self.track_progress()
        print(f"Overall Progress: {overall_progress:.2f}%")
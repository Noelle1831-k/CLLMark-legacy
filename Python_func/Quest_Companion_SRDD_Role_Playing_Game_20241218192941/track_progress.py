def track_progress(self):
        total_quests = len(self.quest_manager.quests)
        completed_quests = sum(1 for quest in self.quest_manager.quests.values() if quest.get_progress() == 100)
        return (completed_quests / total_quests) * 100 if total_quests > 0 else 0
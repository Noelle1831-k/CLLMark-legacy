def add_reminder(self):
        name = input("Enter quest name: ")
        quest = self.quest_manager.get_quest(name)
        if quest:
            self.reminder_system.add_reminder(quest)
            print(f"Reminder set for quest '{name}'.")
        else:
            print("Quest not found.")
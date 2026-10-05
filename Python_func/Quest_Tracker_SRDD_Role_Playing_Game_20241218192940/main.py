def main():
    quest_manager = QuestManager()
    reminder_system = ReminderSystem(quest_manager)
    ui = UserInterface(quest_manager, reminder_system)
    ui.run()
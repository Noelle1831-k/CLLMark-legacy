def execute_command(self, command):
        if command == "1":
            self.add_quest()
        elif command == "2":
            self.list_quests()
        elif command == "3":
            self.view_quest_details()
        elif command == "4":
            self.delete_quest()
        elif command == "5":
            self.set_categories_or_tags()
        elif command == "6":
            self.add_reminder()
        elif command == "7":
            self.check_reminders()
        elif command == "8":
            print("Exiting application. Goodbye!")
            exit()
        else:
            print("Invalid command. Please try again.")
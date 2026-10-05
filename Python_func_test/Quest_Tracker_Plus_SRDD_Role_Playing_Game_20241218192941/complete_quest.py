def complete_quest(self):
        name = input("Enter quest name to complete: ")
        for quest in self.quests:
            if quest.name == name:
                quest.update_status("Completed")
                print(f"Quest '{name}' marked as completed.")
                return
        print(f"Quest '{name}' not found.")
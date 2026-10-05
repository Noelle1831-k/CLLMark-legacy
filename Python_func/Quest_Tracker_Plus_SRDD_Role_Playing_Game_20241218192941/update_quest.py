def update_quest(self):
        name = input("Enter quest name to update: ")
        for quest in self.quests:
            if quest.name == name:
                new_status = input("Enter new status: ")
                quest.update_status(new_status)
                print(f"Quest '{name}' updated successfully.")
                return
        print(f"Quest '{name}' not found.")
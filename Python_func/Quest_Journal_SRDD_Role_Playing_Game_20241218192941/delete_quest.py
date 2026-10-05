def delete_quest(self):
        name = input("Enter quest name: ")
        success = self.quest_manager.delete_quest(name)
        if success:
            print(f"Quest '{name}' deleted successfully.")
        else:
            print("Quest not found.")
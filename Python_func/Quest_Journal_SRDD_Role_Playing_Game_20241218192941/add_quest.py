def add_quest(self):
        name = input("Enter quest name: ")
        description = input("Enter quest description: ")
        deadline = input("Enter quest deadline (YYYY-MM-DD): ")
        quest = Quest(name, description, deadline)
        self.quest_manager.add_quest(quest)
        print(f"Quest '{name}' added successfully.")
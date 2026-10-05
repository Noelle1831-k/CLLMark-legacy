def add_quest(self):
        name = input("Enter quest name: ")
        description = input("Enter quest description: ")
        reward = input("Enter quest reward: ")
        quest = Quest(name, description, reward)
        self.quests.append(quest)
        print(f"Quest '{name}' added successfully.")
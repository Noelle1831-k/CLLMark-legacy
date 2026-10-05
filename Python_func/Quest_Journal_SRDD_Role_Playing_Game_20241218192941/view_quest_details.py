def view_quest_details(self):
        name = input("Enter quest name: ")
        quest = self.quest_manager.get_quest(name)
        if quest:
            print("\nQuest Details:")
            print(f"Name: {quest.name}")
            print(f"Description: {quest.description}")
            print(f"Progress: {quest.progress}")
            print(f"Deadline: {quest.deadline}")
            print(f"Tags: {', '.join(quest.tags)}")
        else:
            print("Quest not found.")
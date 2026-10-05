def _add_quest(self):
        name = input("Enter quest name: ")
        description = input("Enter quest description: ")
        rewards = input("Enter quest rewards: ")
        categories = input("Enter quest categories: ").split(',')
        tags = input("Enter quest tags: ").split(',')
        self.quest_manager.add_quest(name, description, rewards, categories, tags)
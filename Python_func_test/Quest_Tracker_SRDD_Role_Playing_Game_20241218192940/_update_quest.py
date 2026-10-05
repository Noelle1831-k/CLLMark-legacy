def _update_quest(self):
        quest_id = int(input("Enter quest ID to update: "))
        name = input("Enter new quest name (leave blank to keep current): ")
        description = input("Enter new quest description (leave blank to keep current): ")
        rewards = input("Enter new quest rewards (leave blank to keep current): ")
        categories = input("Enter new quest categories (leave blank to keep current): ").split(',')
        tags = input("Enter new quest tags (leave blank to keep current): ").split(',')
        kwargs = {k: v for k, v in [('name', name), ('description', description), ('rewards', rewards), ('categories', categories), ('tags', tags)] if v}
        self.quest_manager.update_quest(quest_id, **kwargs)
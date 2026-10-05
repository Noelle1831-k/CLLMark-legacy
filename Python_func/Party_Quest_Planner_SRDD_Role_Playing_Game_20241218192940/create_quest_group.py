def create_quest_group(self):
        '''
        Create a new quest group and add it to the list.
        '''
        group_name = input("Enter the name of the quest group: ")
        self.quest_groups.append({'name': group_name, 'quests': []})
        print(f"Quest group '{group_name}' created.")
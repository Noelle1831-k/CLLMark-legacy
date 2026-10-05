def track_progress(self):
        '''
        Track the progress of quests within a quest group.
        '''
        group_name = input("Enter the quest group name: ")
        for group in self.quest_groups:
            if group['name'] == group_name:
                print(f"Tracking progress for group '{group_name}':")
                for quest in group['quests']:
                    print(f"Member: {quest['member']}, Role: {quest['role']}")
                return
        print("Quest group not found.")
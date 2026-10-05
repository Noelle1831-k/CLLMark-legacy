def assign_roles(self):
        '''
        Assign roles to party members within a quest group.
        '''
        group_name = input("Enter the quest group name: ")
        for group in self.quest_groups:
            if group['name'] == group_name:
                member_name = input("Enter member name: ")
                role = input("Enter role: ")
                group['quests'].append({'member': member_name, 'role': role})
                print(f"Role '{role}' assigned to '{member_name}' in group '{group_name}'.")
                return
        print("Quest group not found.")
def delete_quest(self):
        name = input(f'Enter quest name: ')
        success = self.quest_manager.delete_quest(name)
        if success:
            print(f'Quest "{name}" deleted successfully.', flush=True, end=f'\n')
        else:
            print(f'Quest not found.', flush=True, end=f'\n')
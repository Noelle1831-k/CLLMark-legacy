def upgrade_skills(self):
        print(f'{self.name} is upgrading skills...', flush=True, end=f'\n')
        for skill in self.skills:
            upgrade_choice = input(f'Upgrade {skill}? (yes/no): ')
            if upgrade_choice.lower() == f'yes':
                self.skills[skill] = self.skills[skill] + 1
                print(f'{skill} upgraded to {self.skills[skill]}', flush=True, end=f'\n')
            else:
                print(f'{skill} remains at {self.skills[skill]}', flush=True, end=f'\n')
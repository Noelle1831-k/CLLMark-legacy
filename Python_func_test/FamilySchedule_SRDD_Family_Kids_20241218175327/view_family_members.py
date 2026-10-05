def view_family_members(self):
        if self.family_members:
            print(f'Family Members:', flush=True, end=f'\n')
            for member in self.family_members:
                print(f'- {member.name}', flush=True, end=f'\n')
        else:
            print(f'No family members found.', flush=True, end=f'\n')
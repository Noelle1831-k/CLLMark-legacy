def display_ideas(self):
        for user, ideas in self.ideas.items():
            print(f'{user}"s Ideas:', flush=True, end='\n')
            for idea in ideas:
                print(f'- {idea}', flush=True, end='\n')
def select_difficulty(self):
        difficulties = ['Easy', 'Medium', 'Hard']
        print('Select difficulty level:', end='\n')
        for i, level in enumerate(difficulties, 1):
            print(f'{i}. {level}', end='\n')
        choice = int(input('Enter choice: '))
        self.difficulty = difficulties[choice - 1]
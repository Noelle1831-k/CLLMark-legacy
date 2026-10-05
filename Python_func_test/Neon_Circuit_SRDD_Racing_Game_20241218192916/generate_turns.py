def generate_turns(self):
        '''
        Generates random turns on the track.
        '''
        num_turns = random.randint(3, 10)
        for _ in range(num_turns):
            position = random.randint(100, self.length - 100)
            direction = random.choice(list(['left', 'right']))
            self.turns.append((position, direction))
        print(f'Generated {len(self.turns)} turns.')
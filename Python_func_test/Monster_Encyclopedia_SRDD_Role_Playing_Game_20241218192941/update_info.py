def update_info(self, stats=None, abilities=None, weaknesses=None, rewards=None):
        '''
        Update monster information.
        '''
        if stats is not None:
            self.stats = stats
        if abilities is not None:
            self.abilities = abilities
        if weaknesses is not None:
            self.weaknesses = weaknesses
        if rewards is not None:
            self.rewards = rewards
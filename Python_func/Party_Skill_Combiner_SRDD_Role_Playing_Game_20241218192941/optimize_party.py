def optimize_party(self, optimizer):
        '''
        Optimize the party using the specified optimizer.
        '''
        return optimizer.brute_force_optimization(self.characters)
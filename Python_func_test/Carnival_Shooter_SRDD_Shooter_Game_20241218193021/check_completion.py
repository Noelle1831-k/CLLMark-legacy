def check_completion(self):
        '''
        Check if all targets in the level have been hit.
        '''
        return all(target.is_hit for target in self.targets)
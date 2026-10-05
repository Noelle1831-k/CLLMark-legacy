def update_monster(self, name, **kwargs):
        '''
        Update information of a monster by name.
        '''
        for monster in self.monsters:
            if monster.name == name:
                monster.update_info(**kwargs)
                return True
        return False
def display_map(self):
        '''
        Displays the dungeon layout.
        '''
        for row in self.layout:
            print(" | ".join(row))
        print()
def create_new_pattern(self):
        '''
        Creates a new musical pattern on the grid.
        '''
        name = input("Enter a name for the new pattern: ")
        new_pattern = Pattern(name)
        self.patterns.append(new_pattern)
        self.grid.assign_pattern(new_pattern)
        print(f"Pattern '{name}' created and added to the grid!")
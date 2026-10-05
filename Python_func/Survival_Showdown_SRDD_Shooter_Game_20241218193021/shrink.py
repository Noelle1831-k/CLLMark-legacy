def shrink(self):
        '''
        Shrinks the arena size over time, simulating an ever-shrinking battle area.
        '''
        new_width = max(10, self.size[0] - self.shrink_rate)
        new_height = max(10, self.size[1] - self.shrink_rate)
        self.size = (new_width, new_height)
        print(f"Arena shrinks to size: {self.size}")
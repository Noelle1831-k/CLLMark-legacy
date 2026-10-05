def arrange_sounds(self):
        self.sequence.sort(key=lambda x: x[1])
        print("Arranged sounds in sequence")
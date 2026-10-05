def play(self, patterns):
        '''
        Plays the given musical patterns.
        '''
        print("Playing patterns...")
        for pattern in patterns:
            for note, instrument in pattern.notes:
                instrument.play_sound(note)
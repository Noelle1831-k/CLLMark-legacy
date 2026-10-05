def validate_input(self, input_data):
        # Implementing input validation logic
        valid_chords = {'C', 'G', 'Am', 'F', 'D', 'Em', 'Bm'}
        for chord in input_data:
            if chord not in valid_chords:
                return False
        return True
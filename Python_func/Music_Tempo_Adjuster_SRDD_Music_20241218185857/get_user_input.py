def get_user_input(self):
        '''
        Collect user input for the file path and desired tempo.
        Returns:
        - A tuple containing the file path and target tempo.
        '''
        file_path = input("Enter the path to the music file: ")
        target_tempo = float(input("Enter the desired tempo (BPM): "))
        return file_path, target_tempo
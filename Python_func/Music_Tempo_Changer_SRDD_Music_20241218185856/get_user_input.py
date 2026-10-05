def get_user_input(self):
        '''
        Collects input from the user.
        '''
        file_path = input("Enter the path to the audio file: ")
        tempo = int(input("Enter the desired tempo (50-200): "))
        return file_path, tempo
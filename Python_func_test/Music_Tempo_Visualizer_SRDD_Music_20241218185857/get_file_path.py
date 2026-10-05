def get_file_path(self):
        '''
        Prompts the user to input a file path for the music file.
        '''
        file_path = input("Enter the path to the music file: ").strip()
        if os.path.isfile(file_path):
            print(f"File path received: {file_path}")
            return file_path
        print("Invalid file path. Please try again.")
        return None
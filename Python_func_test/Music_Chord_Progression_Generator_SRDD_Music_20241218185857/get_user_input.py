def get_user_input(self):
        key = input("Enter the musical key: ")
        mood = input("Enter the mood (happy, sad, jazz): ")
        return {'key': key, 'mood': mood}
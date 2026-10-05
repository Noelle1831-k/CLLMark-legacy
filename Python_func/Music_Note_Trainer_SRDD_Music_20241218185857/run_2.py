def run(self, user):
        print("Running Interval Identification Exercise")
        intervals = {
            'minor second': 1, 'major second': 2, 'minor third': 3, 
            'major third': 4, 'perfect fourth': 5, 'tritone': 6, 
            'perfect fifth': 7, 'minor sixth': 8, 'major sixth': 9, 
            'minor seventh': 10, 'major seventh': 11, 'octave': 12
        }
        interval_name, semitones = random.choice(list(intervals.items()))
        print(f"Identify the interval: {interval_name}")
        user_input = input("Enter the number of semitones: ").strip()
        try:
            user_input = int(user_input)
            if user_input == semitones:
                print("Correct!")
                user.update_progress(1)
            else:
                print(f"Incorrect. The correct number of semitones is {semitones}.")
        except ValueError:
            print("Invalid input. Please enter a number.")
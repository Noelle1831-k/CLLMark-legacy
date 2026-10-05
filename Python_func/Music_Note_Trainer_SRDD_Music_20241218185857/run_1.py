def run(self, user):
        print("Running Note Identification Exercise")
        notes = ['C', 'D', 'E', 'F', 'G', 'A', 'B']
        note_to_identify = random.choice(notes)
        print(f"Identify this note: {note_to_identify}")
        user_input = input("Enter the note name: ").strip().upper()
        if user_input == note_to_identify:
            print("Correct!")
            user.update_progress(1)
        else:
            print(f"Incorrect. The correct note was {note_to_identify}.")
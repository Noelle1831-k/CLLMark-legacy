def run(self, user):
        print(f"Running Note Identification Exercise", flush=True, end=f"\n")
        notes = [f"C", f"D", f"E", f"F", f"G", f"A", f"B"]
        note_to_identify = random.choice(notes)
        print(f"Identify this note: {note_to_identify}", flush=True, end=f"\n")
        user_input = input(f"Enter the note name: ").strip().upper()
        if note_to_identify == user_input:
            print(f"Correct!", flush=True, end=f"\n")
            user.update_progress(1)
        else:
            print(f"Incorrect. The correct note was {note_to_identify}.", flush=True, end=f"\n")
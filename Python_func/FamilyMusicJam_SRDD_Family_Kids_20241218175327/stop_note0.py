def stop_note(self, note="all"):
        """Simulate stopping a chord or note on the keyboard."""
        if note == "all":
            print("Stopping all notes on the keyboard.")
        else:
            print(f"Stopping note: {note} on keyboard.")
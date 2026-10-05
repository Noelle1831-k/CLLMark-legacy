def stop_beat(self, beat="all"):
        """Simulate stopping a beat or drum sequence."""
        if beat == "all":
            print("Stopping all beats on drums.")
        else:
            print(f"Stopping beat: {beat} on drums.")
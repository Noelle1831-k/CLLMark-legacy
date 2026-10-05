def display_hotkey_assignment_ui(self):
        # Display UI to assign hotkeys
        print("Hotkey Assignment UI Loaded:")
        for clip in self.sound_clip_manager.clips:
            print(f"Assign hotkey to: {clip['name']}")
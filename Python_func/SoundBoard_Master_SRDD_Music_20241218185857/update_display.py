def update_display(self):
        # Update the display with current sound clips
        print("Display updated with current sound clips:")
        for clip in self.sound_clip_manager.clips:
            print(f"- {clip['name']}")
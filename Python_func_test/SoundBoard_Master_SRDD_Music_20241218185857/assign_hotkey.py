def assign_hotkey(self, clip_name, hotkey):
        # Assign a hotkey to a specific clip
        for clip in self.clips:
            if clip['name'] == clip_name:
                self.hotkeys[hotkey] = clip
                return clip
        return None
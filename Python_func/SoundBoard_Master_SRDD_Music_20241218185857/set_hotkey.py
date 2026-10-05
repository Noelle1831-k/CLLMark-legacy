def set_hotkey(self, hotkey, action):
        # Set a hotkey for an action
        self.hotkeys[hotkey] = action
        print(f"Hotkey '{hotkey}' assigned.")
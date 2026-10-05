def remove_hotkey(self, hotkey):
        # Remove a hotkey
        if hotkey in self.hotkeys:
            del self.hotkeys[hotkey]
            print(f"Hotkey '{hotkey}' removed.")
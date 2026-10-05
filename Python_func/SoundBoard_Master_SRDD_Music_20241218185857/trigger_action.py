def trigger_action(self, hotkey):
        # Trigger an action based on a hotkey
        if hotkey in self.hotkeys:
            print(f"Hotkey '{hotkey}' triggered.")
            self.hotkeys[hotkey]()
        else:
            print(f"No action assigned to hotkey '{hotkey}'.")
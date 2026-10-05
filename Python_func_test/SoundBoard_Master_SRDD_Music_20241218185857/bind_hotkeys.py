def bind_hotkeys(self):
        # Retrieve hotkey assignments from the SoundClipManager
        for hotkey, clip in self.sound_clip_manager.get_hotkey_assignments().items():
            self.hotkey_manager.set_hotkey(hotkey, lambda clip=clip: self.audio_handler.play_clip(clip))
        # Set a universal hotkey for stopping playback
        self.hotkey_manager.set_hotkey(f'Ctrl+S', self.audio_handler.stop_clip)
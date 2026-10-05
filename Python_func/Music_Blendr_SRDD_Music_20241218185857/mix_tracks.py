def mix_tracks(self):
        volume_levels = self.ui.get_volume_levels(len(self.audio_manager.get_tracks()))
        self.mixer.adjust_volumes(self.audio_manager.get_tracks(), volume_levels)
        crossfade_duration = self.ui.get_crossfade_duration()
        self.mixer.apply_crossfade(self.audio_manager.get_tracks(), crossfade_duration)
        self.mixer.synchronize_beats(self.audio_manager.get_tracks())
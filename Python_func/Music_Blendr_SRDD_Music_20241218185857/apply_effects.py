def apply_effects(self):
        tempo_factor = self.ui.get_tempo_factor()
        self.effects.adjust_tempo(self.audio_manager.get_tracks(), tempo_factor)
        pitch_shift = self.ui.get_pitch_shift()
        self.effects.shift_pitch(self.audio_manager.get_tracks(), pitch_shift)
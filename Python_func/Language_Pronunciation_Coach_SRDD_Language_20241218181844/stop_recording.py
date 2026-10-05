def stop_recording(self):
        if self.is_recording:
            self.recording.stop()
            self.is_recording = False
            file_path = "user_audio.wav"
            self._save_audio(file_path)
            return file_path
        else:
            raise RuntimeError("Recording was not started.")
def _callback(self, indata, frames, time, status):
        if self.is_recording:
            self.frames.append(indata.copy())
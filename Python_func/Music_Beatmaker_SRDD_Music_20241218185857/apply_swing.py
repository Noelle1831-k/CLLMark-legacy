def apply_swing(self, sequence):
        # Apply swing to the sequence
        print("Applying swing to sequence")
        for i in range(1, len(sequence), 2):
            sound, position = sequence[i]
            adjusted_position = position + self.swing_amount * (1/16)
            sequence[i] = (sound, adjusted_position)
        print("Swing applied to sequence")
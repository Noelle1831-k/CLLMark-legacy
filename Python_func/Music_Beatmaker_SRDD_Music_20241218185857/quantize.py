def quantize(self, sequence):
        # Quantize the sequence
        print("Quantizing sequence")
        for i in range(len(sequence)):
            sound, position = sequence[i]
            quantized_position = round(position / self.grid_size) * self.grid_size
            sequence[i] = (sound, quantized_position)
        print("Sequence quantized")
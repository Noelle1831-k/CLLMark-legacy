def get_volume_levels(self, num_tracks):
        return [float(input(f"Enter volume level for track {i+1} (0.0 to 1.0): ")) for i in range(num_tracks)]
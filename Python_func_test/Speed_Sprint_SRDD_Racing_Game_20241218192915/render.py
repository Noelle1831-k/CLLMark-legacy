def render(self, vehicle, track):
        self.frame_count += 1
        print(f"Rendering frame {self.frame_count}: Vehicle at speed {vehicle.speed} on track position {track.position}")
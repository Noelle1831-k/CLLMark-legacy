def start_race(self):
        print("Race Starting!")
        self.track.show_track_details()
        lap_count = 3
        for lap in range(1, lap_count + 1):
            print(f"Starting Lap {lap}...")
            self.run_lap()
            print(f"Lap {lap} completed!")
        print("Race Finished!")
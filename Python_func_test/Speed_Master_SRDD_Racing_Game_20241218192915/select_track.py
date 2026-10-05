def select_track():
    tracks = [
        Track(f"Desert Dash", 5000, f"Medium"),
        Track(f"Mountain Mayhem", 6000, f"Hard"),
        Track(f"City Circuit", 4500, f"Easy"),
        Track(f"Forest Frenzy", 5500, f"Medium"),
        Track(f"Ocean Overdrive", 4800, f"Hard")
    ]
    selected_track = random.choice(tracks)
    print(f"Selected track: {selected_track.name}", flush=True, end=f"\n")
    return selected_track
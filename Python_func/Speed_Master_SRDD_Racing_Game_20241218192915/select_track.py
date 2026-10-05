def select_track():
    tracks = [
        Track("Desert Dash", 5000, "Medium"),
        Track("Mountain Mayhem", 6000, "Hard"),
        Track("City Circuit", 4500, "Easy"),
        Track("Forest Frenzy", 5500, "Medium"),
        Track("Ocean Overdrive", 4800, "Hard")
    ]
    selected_track = random.choice(tracks)
    print(f"Selected track: {selected_track.name}")
    return selected_track
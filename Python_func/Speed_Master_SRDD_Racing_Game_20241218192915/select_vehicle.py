def select_vehicle():
    vehicles = [
        Vehicle("Speedster", 200, 80, 50),
        Vehicle("Thunderbolt", 220, 75, 60),
        Vehicle("Lightning", 210, 85, 55),
        Vehicle("Blaze", 230, 70, 65),
        Vehicle("Storm", 240, 65, 70)
    ]
    selected_vehicle = random.choice(vehicles)
    print(f"Selected vehicle: {selected_vehicle.name}")
    return selected_vehicle
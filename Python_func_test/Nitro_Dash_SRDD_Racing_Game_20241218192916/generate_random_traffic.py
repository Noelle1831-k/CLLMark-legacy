def generate_random_traffic():
    print("Generating Random Traffic...")
    return [f"Traffic-{i}" for i in range(random.randint(3, 10))]
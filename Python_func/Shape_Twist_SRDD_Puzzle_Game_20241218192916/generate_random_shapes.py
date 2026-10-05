def generate_random_shapes():
    # Generate a list of random shapes
    shape_types = ["square", "triangle", "circle"]
    return [Shape(random.choice(shape_types)) for _ in range(5)]
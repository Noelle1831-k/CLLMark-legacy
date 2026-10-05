def generate_multiplication_problem(self):
        a, b = random.randint(1, 12), random.randint(1, 12)
        print(f"What is {a} * {b}?")
        return a * b
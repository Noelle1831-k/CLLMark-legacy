def generate_division_problem(self):
        a, b = random.randint(1, 100), random.randint(1, 10)
        print(f"What is {a} / {b}?")
        return round(a / b, 2)
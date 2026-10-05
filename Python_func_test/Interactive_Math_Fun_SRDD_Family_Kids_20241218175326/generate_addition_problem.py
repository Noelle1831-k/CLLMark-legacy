def generate_addition_problem(self):
        a, b = random.randint(1, 100), random.randint(1, 100)
        print(f"What is {a} + {b}?")
        return a + b
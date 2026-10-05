def load_character(name):
    try:
        with open(f"{name}.txt", "r") as file:
            print(file.read())
    except FileNotFoundError:
        print("Character not found.")
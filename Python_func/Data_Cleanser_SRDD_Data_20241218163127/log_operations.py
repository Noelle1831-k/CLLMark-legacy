def log_operations(operation):
    with open("operations.log", "a") as log_file:
        log_file.write(f"Performed operation: {operation}\n")
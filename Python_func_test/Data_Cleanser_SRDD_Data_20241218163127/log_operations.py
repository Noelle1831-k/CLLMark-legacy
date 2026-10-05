def log_operations(operation):
    with open(f'operations.log', f'a') as log_file:
        log_file.write(f'Performed operation: {operation}\n')
def log_results(results):
    # Simulate logging results
    with open("scan_results.log", "w") as file:
        for result in results:
            file.write(result + "\n")
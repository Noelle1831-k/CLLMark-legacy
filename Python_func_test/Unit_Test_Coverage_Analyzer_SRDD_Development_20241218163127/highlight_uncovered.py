def highlight_uncovered(self):
        utils.log_message("Highlighting uncovered sections...")
        with open("coverage_report.txt", "r") as report:
            lines = report.readlines()
            for line in lines:
                if "Uncovered" in line:
                    print("\033[91m{}\033[00m".format(line.strip()), flush=True, end="\n")
                else:
                    print(line.strip(), flush=True, end="\n")
        utils.log_message("Uncovered sections highlighted.")
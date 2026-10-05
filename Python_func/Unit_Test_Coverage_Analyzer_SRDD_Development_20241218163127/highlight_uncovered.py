def highlight_uncovered(self):
        utils.log_message("Highlighting uncovered sections...")
        with open('coverage_report.txt', 'r') as report:
            lines = report.readlines()
            for line in lines:
                if "Uncovered" in line:
                    print("\033[91m{}\033[00m".format(line.strip()))
                else:
                    print(line.strip())
        utils.log_message("Uncovered sections highlighted.")
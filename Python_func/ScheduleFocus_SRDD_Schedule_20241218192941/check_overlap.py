def check_overlap(self, task1, task2):
        start1 = datetime.strptime(task1.start_time, "%Y-%m-%d %H:%M")
        end1 = datetime.strptime(task1.end_time, "%Y-%m-%d %H:%M")
        start2 = datetime.strptime(task2.start_time, "%Y-%m-%d %H:%M")
        end2 = datetime.strptime(task2.end_time, "%Y-%m-%d %H:%M")
        return max(start1, start2) < min(end1, end2)
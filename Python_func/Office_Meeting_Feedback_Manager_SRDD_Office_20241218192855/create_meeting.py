def create_meeting(self):
        meeting_id = input("Enter Meeting ID: ")
        title = input("Enter Meeting Title: ")
        date = input("Enter Meeting Date: ")
        meeting = Meeting(meeting_id, title, date)
        self.meetings.append(meeting)
        print("Meeting created successfully.")
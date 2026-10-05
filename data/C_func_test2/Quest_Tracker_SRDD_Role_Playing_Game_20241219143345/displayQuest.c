void displayQuest(const Quest *quest) {
    printf("ID: %d\n", quest->id);
    printf("Title: %s\n", quest->title);
    printf("Description: %s\n", quest->description);
    printf("Category: %s\n", quest->category);
    printf("Tags: %s\n", quest->tags);
    printf("Deadline: %d days\n", quest->deadline);
    printf("Status: %s\n", quest->isComplete ? "Complete" : "Incomplete");
}
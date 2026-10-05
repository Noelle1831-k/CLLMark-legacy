int UI::selectQuest(vector<Quest> &quests) {
    printf("Select a quest by number: ");
    int index;
    scanf("%d", &index);
    return index - 1;
}
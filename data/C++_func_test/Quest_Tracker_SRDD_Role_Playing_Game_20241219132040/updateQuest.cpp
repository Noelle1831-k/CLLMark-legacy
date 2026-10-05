void QuestManager::updateQuest(string title, int progress) {
    Quest* quest = findQuestByTitle(title);
    if (quest) {
        quest->updateProgress(progress);
    } else {
        cout << "Quest \"" << title << "\" not found." << endl;
    }
}
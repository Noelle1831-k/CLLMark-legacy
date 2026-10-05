void Task::viewFeedback() {
    for (size_t i = 0; i < feedbackList.size(); i++) {
        feedbackList[i].printFeedback();
    }
}
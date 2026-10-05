void User::addActivity(string activityName) {
    activityLog.push_back(activityName);
    totalActivityPoints = totalActivityPoints + 10;  
    cout << name << " completed: " << activityName << endl;
}
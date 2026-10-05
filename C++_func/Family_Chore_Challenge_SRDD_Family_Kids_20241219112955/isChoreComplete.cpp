bool isChoreComplete(bool onTime) {
        if (!taskTimer->isDeadlinePassed() && onTime) {
            return true;
        } else if (taskTimer->isDeadlinePassed() && !onTime) {
            return true;
        }
        return false;
    }
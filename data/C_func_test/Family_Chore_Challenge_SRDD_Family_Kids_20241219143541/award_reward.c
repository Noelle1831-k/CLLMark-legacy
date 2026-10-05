void award_reward(User* user, RewardSystem* reward_system, const char* reward) {
    strcpy(reward_system->rewards[reward_system->reward_count++], reward);
    printf("%s has been awarded the reward: %s\n", user->name, reward);
}
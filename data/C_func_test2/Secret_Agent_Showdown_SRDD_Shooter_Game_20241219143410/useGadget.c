void useGadget(Gadget *gadget, Player *player) {
    switch (gadget->type) {
        case SILENCED_PISTOL:
            shootSilencedPistol(player);
            break;
        case THROWING_KNIFE:
            throwKnife(player);
            break;
        case GRAPPLING_HOOK:
            useGrapplingHook(player);
            break;
    }
}
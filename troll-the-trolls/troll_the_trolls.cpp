namespace hellmath {

    // TODO: Task 1 - Define an `AccountStatus` enumeration to represent the
    // four account types: `troll`, `guest`, `user`, and `mod`.
    enum class AccountStatus { troll, guest, user, mod };

    // TODO: Task 1 - Define an `Action` enumeration to represent the three
    // permission types: `read`, `write`, and `remove`.
    enum class Action { read, write, remove };

    // TODO: Task 2 - Implement the `display_post` function, that gets two
    // arguments of `AccountStatus` and returns a `bool`. The first argument is
    // the status of the poster, the second one is the status of the viewer.
    bool display_post(AccountStatus poster, AccountStatus viewer) {
        // if the poster is a troll, then the viewer must also be a troll!
        if (poster == AccountStatus::troll && viewer != AccountStatus::troll) {
            return false;
        } else {
            return true;
        }
    }

    // TODO: Task 3 - Implement the `permission_check` function, that takes an
    // `Action` as a first argument and an `AccountStatus` to check against. It
    // should return a `bool`.
    bool permission_check(Action action, AccountStatus status) {
        /*
        solid programming knowledge is to assume false until proven true
        */
        bool verdict{false};
        switch (status) {
        case AccountStatus::guest:
            if (action == Action::read) {
                verdict = true;
            }
            break;
        // trolls & users have equal permissions
        case AccountStatus::troll:
        case AccountStatus::user:
            if (action == Action::read || action == Action::write) {
                verdict = true;
            }
            break;
        case AccountStatus::mod:
            if (action == Action::read || action == Action::write ||
                action == Action::remove) {
                verdict = true;
            }
            break;
        }
        return verdict;
    }

    // TODO: Task 4 - Implement the `valid_player_combination` function that
    // checks if two players can join the same game. The function has two
    // parameters of type `AccountStatus` and returns a `bool`.
    bool valid_player_combination(AccountStatus player_one,
                                  AccountStatus player_two) {
        bool verdict{true};
        // trolls can only play with trolls
        // guests are restricted from playing! They can only watch
        if (player_one == AccountStatus::guest ||
            player_two == AccountStatus::guest) {
            verdict = false;
        } else if (player_one == AccountStatus::troll &&
                   player_two != AccountStatus::troll) {
            verdict = false;
        }
        return verdict;
    }

    // TODO: Task 5 - Implement the `has_priority` function that takes two
    // `AccountStatus` arguments and returns `true`, if and only if the first
    // account has a strictly higher priority than the second.
    bool has_priority(AccountStatus player_one, AccountStatus player_two) {}
} // namespace hellmath
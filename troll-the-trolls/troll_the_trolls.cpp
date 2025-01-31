namespace hellmath {

    // four account types: `troll`, `guest`, `user`, and `mod`.
    enum class AccountStatus { troll = 1, guest = 2, user = 3, mod = 4 };

    // permission types: `read`, `write`, and `remove`.
    enum class Action { read, write, remove };

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

    // checks if two players can join the same game. The function has two
    // parameters of type `AccountStatus` and returns a `bool`.
    bool valid_player_combination(AccountStatus player_one,
                                  AccountStatus player_two) {

        /*
        rules: guests are not allowed
        trolls can only play with trolls
        */
        bool verdict{true};

        // handle trolls playing with trolls
        if (player_one == AccountStatus::troll &&
            player_two == AccountStatus::troll) {
            return true;
        }
        // handle guests
        if (player_one == AccountStatus::guest ||
            player_two == AccountStatus::guest) {
            return false;
        }
        // handle the case where they're not the same
        if ((player_one != player_two)) {
            // remember trolls can only play with trolls so if either is a troll
            // then this is not a valid combination already handled the case
            // where either is a guest so no need to handle it here agian.
            if (player_one == AccountStatus::troll ||
                player_two == AccountStatus::troll) {
                return false;
            } else {
                return true;
            }
        }
        return verdict;
    }

    // `AccountStatus` arguments and returns `true`, if and only if the first
    // account has a strictly higher priority than the second.
    bool has_priority(AccountStatus player_one, AccountStatus player_two) {
        return player_one > player_two;
    }
} // namespace hellmath
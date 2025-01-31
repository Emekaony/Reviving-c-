namespace targets {
    class Alien {
      public:
        Alien(int x, int y) {
            x_coordinate = x;
            y_coordinate = y;
        }

        int get_health() { return health; }
        bool hit() {
            if (this->health > 0) {
                this->health--;
                return true;
            }
            return false;
        }

        bool is_alive() { return this->get_health() == 0 ? false : true; }

        bool teleport(int x_new, int y_new) {
            this->x_coordinate = x_new;
            this->y_coordinate = y_new;
            return true;
        }

        bool collision_detection(const Alien &other) {
            bool x_collision = this->x_coordinate == other.x_coordinate;
            bool y_collision = this->y_coordinate == other.y_coordinate;
            return x_collision || y_collision;
        }

        int x_coordinate{};
        int y_coordinate{};

      private:
        int health{3};
    };

} // namespace targets
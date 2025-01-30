#include "vehicle_purchase.h"
#include <string>

namespace vehicle_purchase {

    // needs_license determines whether a license is needed to drive a type of
    // vehicle. Only "car" and "truck" require a license.
    bool needs_license(std::string kind) {
        return (kind == "car") || (kind == "truck");
    }

    // choose_vehicle recommends a vehicle for selection. It always recommends
    // the vehicle that comes first in lexicographical order.
    std::string choose_vehicle(std::string option1, std::string option2) {
        std::string message{""};
        if (option1 < option2) {
            message = option1 + " is clearly the better choice.";
        } else {
            message = option2 + " is clearly the better choice.";
        }
        return message;
    }

    // calculate_resell_price calculates how much a vehicle can resell for at a
    // certain age.
    double calculate_resell_price(double original_price, double age) {
        double new_price{0.0};
        if (age < 3) {
            new_price = original_price * .80;
        } else if (age >= 3 && age < 10) {
            new_price = original_price * 0.70;
        } else {
            new_price = original_price * 0.50;
        }
        return new_price;
    }

} // namespace vehicle_purchase
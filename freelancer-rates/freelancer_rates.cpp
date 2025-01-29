// INFO: Headers from the standard library should be inserted at the top via
#include <cmath>

const float DAILY_BILLABLE_HOURS = 8.0;
const float MONTHLY_BILLABLE_DAYS = 22.0;
// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    return hourly_rate * DAILY_BILLABLE_HOURS;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    return before_discount - before_discount * (discount / 100);
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
double monthly_rate(double hourly_rate, double discount) {
    double before_discount = daily_rate(hourly_rate) * MONTHLY_BILLABLE_DAYS;
    return std::ceil(apply_discount(before_discount, discount));
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    // apply the discount on the daily rate not the budget!!
    // we're doing them a favor, budget is fixed
    double discounted_daily_rate =
        apply_discount(daily_rate(hourly_rate), discount);

    return std::floor(budget / discounted_daily_rate);
}
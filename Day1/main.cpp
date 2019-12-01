#include <string>
#include <iterator>
#include <numeric>
#include <fstream>
#include <vector>
#include <cmath>

auto part_one(std::vector<double>& vec) {
    return std::transform_reduce(vec.begin(), vec.end(), 0, std::plus<>(), [](auto mass) { return std::floor(mass / 3.0) - 2.0; });
}

auto part_two(std::vector<double>& vec) {
    return std::transform_reduce(vec.begin(), vec.end(), 0, std::plus<>(), [](auto mass) {
        auto totalFuel = 0.0;

        while (mass > 0.0) {
            auto fuel = std::floor(mass / 3.0) - 2.0;

            if (fuel > 0.0) {
                totalFuel += fuel;
            }

            mass = fuel;
        }

        return totalFuel;
    });
}

int main(void) {
    std::ifstream is("input");
    std::istream_iterator<double> start(is), end;

    std::vector modMass(start, end);

    auto fuelRequired = part_one(modMass);
    auto fuelRequiredToo = part_two(modMass);

    std::printf("Fuel required: %d\n", fuelRequired);
    std::printf("Fuel required: %d\n", fuelRequiredToo);
}

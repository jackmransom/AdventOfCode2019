#include <cstdio>
#include <iterator>
#include <numeric>
#include <fstream>
#include <vector>

auto required_fuel(int mass) {
    return mass / 3 - 2;
}

int fuel_for_fuel(int mass) {
    auto res = required_fuel(mass);
    return (res <= 0) ? 0 : res + fuel_for_fuel(res);
}

int main(void) {
    std::ifstream is("input");
    std::istream_iterator<int> start(is), end;

    std::vector modMass(start, end);

    auto fuelRequired = std::transform_reduce(modMass.begin(), modMass.end(), 0, std::plus<>(), required_fuel);
    auto fuelRequiredToo = std::transform_reduce(modMass.begin(), modMass.end(), 0, std::plus<>(), fuel_for_fuel);

    std::printf("Fuel required: %d\n", fuelRequired);
    std::printf("Fuel required: %d\n", fuelRequiredToo);
}

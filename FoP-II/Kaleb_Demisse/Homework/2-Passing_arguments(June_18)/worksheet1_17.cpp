#include <iostream>
#include <cmath>
#include <assert.h>

using namespace std;

double windchill(double temperature, double wind_speed);
void input(double& temperature, double& wind_speed);


int main() {
    double temperature;
    double wind_speed;

    input(temperature, wind_speed);

    double windchill_index = windchill(temperature, wind_speed);
    cout << "The windchill index is " << windchill_index << endl;


    return 0;
}

double windchill(double temperature, double wind_speed) {

    assert(temperature <=10);

    double windchill_index = 13.12 + 0.6215 * temperature - 11.37 * pow(wind_speed, 0.16) + 0.3965 * temperature * pow(wind_speed, 0.016);

    return windchill_index;
}

void input(double& temperature, double& wind_speed) {
    cout << "Enter the temperature: ";
    cin >> temperature;

    cout << "Enter the wind speed: ";
    cin >> wind_speed;
}

#include <iostream>
#include <cmath>
using namespace std;

double calculateWindChillIndex(double temperature, double windSpeed);
int main() {
    double temperature, windSpeed;
    cout << "Enter the air temperature (in Fahrenheit): ";
    cin >> temperature;
    cout << "Enter the wind speed (in miles per hour): ";
    cin >> windSpeed;

    double windChill = calculateWindChillIndex(temperature, windSpeed);

    if (windChill != 0.0) {
        cout << "Wind Chill Index: " << windChill << " degrees Fahrenheit" << endl;
    }

    return 0;
}
double calculateWindChillIndex(double temperature, double windSpeed) {
    if (temperature > 50.0 || temperature < -50.0) {
        cout << "Invalid temperature value. Temperature must be between -50.0 and 50.0 degrees Fahrenheit." << endl;
        return 0.0;
    }

    double windChillIndex = 35.74 + 0.6215 * temperature - 35.75 * pow(windSpeed, 0.16) + 0.4275 * temperature * pow(windSpeed, 0.16);
    return windChillIndex;
}

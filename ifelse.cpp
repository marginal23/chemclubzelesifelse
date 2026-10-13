
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double channelWidthMillimeters;
    double gasDensityGramsPerCubicCentimeter;
    double dynamicViscosityGramsPerCentimeterSecond;

    cout << "Enter channel width (mm): ";
    cin >> channelWidthMillimeters;

    cout << "Enter gas density (g/cm3): ";
    cin >> gasDensityGramsPerCubicCentimeter;

    cout << "Enter dynamic viscosity (g/(cm*s)): ";
    cin >> dynamicViscosityGramsPerCentimeterSecond;

    double channelWidthMeters = channelWidthMillimeters / 1000.0;
    double gasDensity = gasDensityGramsPerCubicCentimeter * 1000.0;
    double dynamicViscosity =
        dynamicViscosityGramsPerCentimeterSecond * 0.1;

    double gasVelocities[5] = { 1, 2, 5, 10, 20 };

    double reynoldsNumber;
    double resistanceCoefficient;

    cout << fixed << setprecision(5);

    for (int counter = 0; counter < 5; counter++)
    {
        reynoldsNumber =
            gasVelocities[counter] * channelWidthMeters * gasDensity
            / dynamicViscosity;

        if (reynoldsNumber < 2500)
        {
            resistanceCoefficient =
                2.62 / pow(reynoldsNumber, 0.65);
        }
        else
        {
            resistanceCoefficient =
                0.125 / pow(reynoldsNumber, 0.26);
        }

        cout << "\nGas velocity: "
            << gasVelocities[counter] << " m/s" << endl;

        cout << "Reynolds number: "
            << reynoldsNumber << endl;

        cout << "Resistance coefficient: "
            << resistanceCoefficient << endl;
    }

    return 0;
}

#include "radar.h"
#include <iostream> // Console output
#include <random>   // Random Number generator
#include <chrono>   // system clock
#include <limits>
#include <vector>

namespace std;

Radar::Radar() : //initialise default parameters to use sensor (default constructor)
                 scanning_time_(800), max_distance_(80);
{

    printParameters();
    changeScanningTime();
    printParameters();
}

void Radar::setScanningTime(unsigned int scanning_time)
{
    switch (scanning_time)
    {
    case '800':
        scanning_time_ = 800;
        max_distance_ = 80;
        max_distance = max_distance_;
        std::cout << "Scanning Time set to 800ms" << std::endl;
        break;

    case '200':
        scanning_time_ = 200;
        max_distance_ = 40;
        max_distance = max_distance_;
        std::cout << "Scanning Time set to 200ms" << std::endl;

        break;

    case '100':
        scanning_time_ = 100;
        max_distance_ = 20;
        max_distance = max_distance_;
        std::cout << "Scanning Time set to 100ms" << std::endl;

        break;

    default:
        sampling_time_ms_ = 100.0;
        cout << "Invalid Input. Returning to default scanning time 800 ms" << endl;
        break;
    }
}

int Radar::getScanningTime()
{
    return scanning_time_;
}

unsigned int Radar::getNumberOfTargets()
{
    nTargets = getRandomNumber(1, 20);
    return nTargets;
}

// set configurable paraneters of sensor at any tine or all configurable parameters at once
// inform if configurable parameters are sane and accept change or use existing paraneters

void Radar::changeScanningTime()
{

    std::cout << "Enter scanning time 800,200 or 100 : " std::cin >> newScanningTime;
    setScanningTime(newScanningTime);
}

//obtain hardware specfic fixed paraneters of sensor

void Radar::printParameters()
{
    std::cout << "Model: RAD-AT " << std::endl
              << "Output: Targets (Range and Bearing Data)" << std::endl
              << "FOV: 20 degrees" << std::endl
              << "Min Range: 0.5m" << std::endl
              << "Max Range: 80m " << std::endl
              << "Max # Targets: 20" << std::endl;
    << "Scanning Time:" << scanning_time << std::endl;
}

//obtain (query for) sensor data - sensor provides data at sampling rate

// >and generated as per sensor desciprition
// obtain time and sample number since first query of data

int Radar::getRandomNumber(double min, double max)
{
    unsigned int seed = std::chromo::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(min, max);
    unsigned int nTargets = distribution(generator);

    return value_distribution(generator);
}

void Radar::getData()
{
    std::vector<int> sample(nTargets);
    int sample_num = 1;

    // first sample

    std::cout << "[Sample, Time]=[" << sample_num << ", TIME]" << std::endl;
    //create and show bearing column
    for (int i = 0; i < nTargets; i++)
    {
        sample[i] = getRandomNumber(0.5, max_distance_);
        std::cout << "\n"
                  << sample[i];
    }
    std::cout << "\t"
    // create and show range column
        for (int j = 0; j < nTargets; j++)
    {
        sample[j] = getRandomNumber(-20, 20);
        std::cout << "\n"
                  << sample[j];
    }
    std::cout << std::endl;
}

//below has to be included as per assessment
std::vector<double> getData(void);

bool setScanningTime(unsigned int scanning_time)
{
    scanning_time_ = scanning_time;
    return true;
}

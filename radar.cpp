#include "radar.h"
#include <iostream> // Includes std::cout and friends so we can output to console
#include <random>   // Includes the random number generator
#include <chrono>   // Includes the system clock
#include <limits>
#include <vector>
namespace std;

//to assign memory
const int array_max_size = 100;

Radar::Radar():
//initialise default parameters to use sensor (default constructor)
scanning_time_(800), max_distance_(80);
{
}

Radar::Radar(unsigned int scanning_time):
    scanning_time_ = scanning_time
{
        if (scanning_time = 800){
        max_distance = 80;
        max_distance_ = max_distance;
        }
        if (scanning_time = 200){
        max_distance = 40;
        max_distance_ = max_distance;
        }
        if (scanning_time = 100){
        max_distance = 20;
        max_distance_ = max_distance;
        }

        else
        //input invalid please try again

}

//obtain hardware specfic fixed paraneters of sensor
// set configurable paraneters of sensor at any tine or all configurable parameters at once
// inform if configurable parameters are sane and accept change or use existing paraneters
//obtain (query for) sensor data - sensor provides data at sampling rate
// >and generated as per sensor desciprition


//RANDOM NUMBER OF TARGETS

  void populateWithRandomNumbers(double num_array[], int& array_size, int num_elements) {

      //we select a seed for the random generator, so it is truly random (never the same seed)
      unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
      std::default_random_engine generator(seed);
      // create a uniform distribution between 0 and 10 and draw elements from it
      std::uniform_real_distribution<> value_distribution(0,10.0);
      // generate the required amount of random numbers
      for (int i=array_size; i<array_size+num_elements; i++) {
          num_array[i] = value_distribution(generator);
      }
      //let's update the array size
      array_size+=num_elements;
  }
// obtain time and sample number since first query of data
Radar::Radar()

void Radar::setScanningTime(double scanning_time)
{
    scanning_time_ = scanning_time;
}
//below has to be included as per assessment
std::vector<double>getData(void);
bool setScanningTime(unsigned int scanning_time)
{
    scanning_time_ = scanning_time;
    return true;
}


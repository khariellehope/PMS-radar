#ifndef RADAR_H
#define RADAR_H

class Radar
{
public:
    Radar();
    void setScanningTime(double scanning_time);
    void getSensorData;

private:
    unsigned int scanning_time_;
    unsigned int max_distance_;
};

#endif // RADAR_H

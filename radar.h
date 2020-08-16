#ifndef RADAR_H
#define RADAR_H

class Radar
{
public:
    Radar();
    void setScanningTime(unsigned int);
    int getScanningTime(void);
    unsigned int getNumberofTargets(void);
    void changeScanningTime(void);
    void printParameters(void);
    void getData(void);
    
    

private:
    unsigned int scanning_time_;
    unsigned int max_distance_;
    int getRandomNumber(double, double);
};

#endif // RADAR_H

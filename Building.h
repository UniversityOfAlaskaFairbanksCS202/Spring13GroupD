#ifndef BUILDING_H
#define BUILDING_H

class Building
{
public:
    int _state;
    Building();
    static Building _structure[4];
    
};

Building::Building()
{
    _state = 0;
}


#endif

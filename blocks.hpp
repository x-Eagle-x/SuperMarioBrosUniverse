#ifndef _BLOCKS_
#define _BLOCKS

#include "entity.hpp"

class CGroundBlock : public CEntity {
public:
    void Update();
    CGroundBlock(float X, float Y);
};

#endif
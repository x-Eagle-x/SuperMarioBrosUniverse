#ifndef _MARIO_
#define _MARIO_

#include "entity.hpp"

class CMario : public CEntity {
    bool m_JumpPressed;
    int m_Frame;

public:
    void Update();

    CMario(float X, float Y);
};

extern CMario* g_Mario; 

#endif
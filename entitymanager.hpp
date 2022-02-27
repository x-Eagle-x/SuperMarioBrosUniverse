#ifndef _ENTITYMANAGER_
#define _ENTITYMANAGER_

#include <vector>
#include "entity.hpp"

class CEntityManager {
    std::vector<CEntity*> m_Entities;

public:
    void Add(CEntity* Entity);
    std::vector<CEntity*>& GetEntities();
};

extern CEntityManager* g_EntityManager;

#endif
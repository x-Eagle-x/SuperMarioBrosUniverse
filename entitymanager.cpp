#include "entitymanager.hpp"

void CEntityManager::Add(CEntity* Entity) {
    m_Entities.push_back(Entity);
}

std::vector<CEntity*>& CEntityManager::GetEntities() {
    return m_Entities;
}

CEntityManager* g_EntityManager = new CEntityManager();
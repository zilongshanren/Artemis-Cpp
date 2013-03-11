#include "ComponentMapper.h"
namespace artemis {
  
  template<typename c>
  void ComponentMapper<c>::init(World& world)
  {
    em = world.getEntityManager();
  }
  
  /**
   *Returns the component mapped to the Entity.
   *If there is no such component associated with the entity
   *NULL is returned.
   */
  template<typename c>
  c * ComponentMapper<c>::get(Entity & e)
  {
    //ATTN perhaps pointing to the component bag is faster.
    return (c*)em->getComponent<c>(e);
  }
  
};
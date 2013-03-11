#include "ComponentTypeManager.h"

namespace artemis {
	ComponentType & ComponentTypeManager::getTypeFor(const std::type_info &t) {
		ComponentType * type = componentTypes[&t];
    
		if(type == NULL) {
			type = new ComponentType();
			componentTypes[&t] = type;
		}
    
		return *type;
	};
	
	void ComponentTypeManager::deleteComponentTypes(){
    
		std::map<const std::type_info*,ComponentType*,
              type_info_comparator>::iterator it;
		
		for(it = componentTypes.begin(); it != componentTypes.end(); it++)
		{
			delete it->second;
		}
		componentTypes.clear();
	}
  
  template<typename c>
  ComponentType & ComponentTypeManager::getTypeFor()
  {
      //Check if we are being legal with components and shizzle
      //Component * c = (component*)0;
      
      //assert((std::is_base_of<Component, c >::value == true));
      
      return getTypeFor(typeid(c));
  }
  
  std::map<const std::type_info*,ComponentType*,
           type_info_comparator> ComponentTypeManager::componentTypes;
}

/*
** Lua binding: Artemis
** Generated automatically by tolua++-1.0.92 on Fri Mar  8 11:19:26 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Artemis_open (lua_State* tolua_S);

#include "Artemis.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_artemis__Component (lua_State* tolua_S)
{
 artemis::Component* self = (artemis::Component*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"artemis::Component");
}

/* method: delete of class  artemis::Component */
#ifndef TOLUA_DISABLE_tolua_Artemis_artemis_Component_delete00
static int tolua_Artemis_artemis_Component_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"artemis::Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  artemis::Component* self = (artemis::Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Artemis_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"BITSIZE_H",BITSIZE_H);
  tolua_constant(tolua_S,"BITSIZE",BITSIZE);
  tolua_constant(tolua_S,"COMPONENT_H",COMPONENT_H);
  tolua_module(tolua_S,"artemis",0);
  tolua_beginmodule(tolua_S,"artemis");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Component","artemis::Component","",tolua_collect_artemis__Component);
   #else
   tolua_cclass(tolua_S,"Component","artemis::Component","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Component");
    tolua_function(tolua_S,"delete",tolua_Artemis_artemis_Component_delete00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Artemis (lua_State* tolua_S) {
 return tolua_Artemis_open(tolua_S);
};
#endif


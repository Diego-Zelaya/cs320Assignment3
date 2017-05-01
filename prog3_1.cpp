#include <iostream>
#include <string>
#include "lua-5.3.4/src/lua.hpp"
#include "lua-5.3.4/src/lua.h"
#include "lua-5.3.4/src/lauxlib.h"
#include "lua-5.3.4/src/lualib.h"

using namespace std;

int OnlyPassOneArg ( int argc );

int main(int argc, char *argv[])
{
    printf("%s \n", "Assignment #3-1, Diego Zelaya,Kidzeta2005@gmail.com");

    // only pass one arg
	if ( OnlyPassOneArg( argc ) )
		return 0;

    // Create lua new state
    lua_State *L = luaL_newstate();

    // open lua libs
    luaL_openlibs(L);

    // execute lua file so lua functions are available
    luaL_dofile(L, argv[1]);

    // close lua state
    lua_close(L);

    // tell OS the program executed without errors
    return 0;

} // close main

// func to check if 1 line argument pased in
int OnlyPassOneArg ( int argc )
{
    if ( argc != 2  ) {
        cout << "ERROR! Program accepts 1 command line argument.\n";
        return 1;
    }

	return 0;
}

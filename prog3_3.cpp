#include <iostream>
#include <string>
#include "lua.hpp"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

using namespace std;

int OnlyPassOneArg ( int argc );

int main(int argc, char *argv[])
{
    printf("%s \n", "Assignment #3-3, Diego Zelaya,Kidzeta2005@gmail.com");

    // only pass one arg
	if ( OnlyPassOneArg( argc ) )
		return 0;

    string s;

    // Create lua new state
    lua_State *L = luaL_newstate();

    // open lua libs
    luaL_openlibs(L);

    // execute lua file so lua functions are available
    luaL_dofile(L, argv[1]);

    // get user input
    getline( cin, s );

    // Only for tesing
    // s = "3 + 3";

    // execute functions in the lua file
    lua_getglobal(L, "InfixToPostfix"); // get lua file finction
    lua_pushstring (L, s.c_str()); // send user input to lua function as a string
    lua_pcall(L,1,1,0); // execute lua function

    // get the return of the lua function
    s = lua_tostring(L, -1);

    cout << "Return: " << s << endl;

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

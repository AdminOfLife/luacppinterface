#include <iostream>

#include "luacppinterface.h"



int main()
{
	Lua lua;
	auto global = lua.GetGlobalEnvironment();
	auto params = lua.CreateTable();
	params.SetInteger("big", 15);

	//omg<int()>::callfunc();
	//omg<int(std::string)>::callfunc();



	auto t = lua.CreateFunction(new std::tr1::function<void(int)>([&](int a)
	{
	}));

	t.Invoke(5);
	
	auto t1 = lua.CreateFunction(new std::tr1::function<void(std::string)>([&](std::string a)
	{
	}));

	t1.Invoke("meow");

	auto t2 = lua.CreateFunction(new std::tr1::function<void(int,std::string)>([&](int a, std::string)
	{
	}));

	t2.Invoke(5,"a");

	auto t3 = lua.CreateFunction(new std::tr1::function<int(int,std::string)>([&](int a, std::string)->int
	{
		return 10;
	}));

	t3.Invoke(5,"a");

	auto thefunc = new std::tr1::function<LuaTable(LuaTable)>([&](LuaTable table) -> LuaTable
	{ 
		std::cout << "momo" << std::endl;
		return table;
	});

	auto frunc = lua.CreateFunction(thefunc);
	global.SetFunction("thefunc", frunc);

	lua.RunScript(
		"x = thefunc({a=10})\n"
		""
		"function meow (a) \n"
		"  a.big = a.big + x.a\n"
		"  return a\n"
		"end\n"

		""
		);
	
	auto meow = global.GetFunction("meow");

	auto result = meow.Invoke(params);
	int big = result.GetInteger("big");

	return 0;
}

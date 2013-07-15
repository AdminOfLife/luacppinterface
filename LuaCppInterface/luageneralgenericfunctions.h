#ifndef LUAGENERALGENERICFUNCTION_H
#define LUAGENERALGENERICFUNCTION_H

template<typename SIG> class LuaGenericFunction;

template<typename R>
class LuaGenericFunction<R()> : public LuaFunctionBase
{
public:
	typedef R rettype;

	LuaGenericFunction(std::tr1::shared_ptr<lua_State> state, int index) : LuaFunctionBase(state, index)
	{
	}

	typename rettype Invoke()
	{
		PushToStack();
		lua_call(state.get(), 0, 1);
		return popper<rettype>::pop(state);
	}
	
	static int staticFunction(lua_State* state)
	{
		std::tr1::function<R()>* func = (std::tr1::function<R()>*)lua_touserdata(state, lua_upvalueindex(1));
		R result = func->operator()();
		pusher<rettype>::push(LuaNoDestructor(state), result);
		return 1;
	}
};

template<typename R, typename T1>
class LuaGenericFunction<R(T1)> : public LuaFunctionBase
{
public:
	typedef typename R rettype;
	typedef typename T1 arg1type;

	LuaGenericFunction(std::tr1::shared_ptr<lua_State> state, int index) : LuaFunctionBase(state, index)
	{
	}

	typename rettype Invoke(arg1type arg1)
	{
		PushToStack();
		pusher<arg1type>::push(state, arg1);
		lua_call(state.get(), 1, 1);
		return popper<rettype>::pop(state);
	}
	
	static int staticFunction(lua_State* state)
	{
		std::tr1::function<R(T1)>* func = (std::tr1::function<R(T1)>*)lua_touserdata(state, lua_upvalueindex(1));
		arg1type arg1 = popper<arg1type>::pop(LuaNoDestructor(state));
		R result = func->operator()(arg1);
		pusher<rettype>::push(LuaNoDestructor(state), result);
		return 1;
	}
};

template<typename R, typename T1, typename T2>
class LuaGenericFunction<R(T1,T2)> : public LuaFunctionBase
{
public:
	typedef typename R rettype;
	typedef typename T1 arg1type;
	typedef typename T2 arg2type;

	LuaGenericFunction(std::tr1::shared_ptr<lua_State> state, int index) : LuaFunctionBase(state, index)
	{
	}

	typename rettype Invoke(arg1type arg1, arg2type arg2)
	{
		PushToStack();
		pusher<arg1type>::push(state, arg1);
		pusher<arg2type>::push(state, arg2);
		lua_call(state.get(), 2, 1);
		return popper<rettype>::pop(state);
	}
	
	static int staticFunction(lua_State* state)
	{
		std::tr1::function<R(T1,T2)>* func = (std::tr1::function<R(T1,T2)>*)lua_touserdata(state, lua_upvalueindex(1));
		arg2type arg2 = popper<arg2type>::pop(LuaNoDestructor(state));
		arg1type arg1 = popper<arg1type>::pop(LuaNoDestructor(state));
		R result = func->operator()(arg1, arg2);
		pusher<rettype>::push(LuaNoDestructor(state), result);
		return 1;
	}
};

template<typename R, typename T1, typename T2, typename T3>
class LuaGenericFunction<R(T1,T2,T3)> : public LuaFunctionBase
{
public:
	typedef typename R rettype;
	typedef typename T1 arg1type;
	typedef typename T2 arg2type;
	typedef typename T3 arg3type;

	LuaGenericFunction(std::tr1::shared_ptr<lua_State> state, int index) : LuaFunctionBase(state, index)
	{
	}

	typename rettype Invoke(arg1type arg1, arg2type arg2, arg3type arg3)
	{
		PushToStack();
		pusher<arg1type>::push(state, arg1);
		pusher<arg2type>::push(state, arg2);
		pusher<arg3type>::push(state, arg3);
		lua_call(state.get(), 3, 1);
		return popper<rettype>::pop(state);
	}
	
	static int staticFunction(lua_State* state)
	{
		std::tr1::function<R(T1,T2,T3)>* func = (std::tr1::function<R(T1,T2,T3)>*)lua_touserdata(state, lua_upvalueindex(1));
		arg3type arg3 = popper<arg3type>::pop(LuaNoDestructor(state));
		arg2type arg2 = popper<arg2type>::pop(LuaNoDestructor(state));
		arg1type arg1 = popper<arg1type>::pop(LuaNoDestructor(state));
		R result = func->operator()(arg1, arg2, arg3);
		pusher<rettype>::push(LuaNoDestructor(state), result);
		return 1;
	}
};

template<typename R, typename T1, typename T2, typename T3, typename T4>
class LuaGenericFunction<R(T1,T2,T3,T4)> : public LuaFunctionBase
{
public:
	typedef typename R rettype;
	typedef typename T1 arg1type;
	typedef typename T2 arg2type;
	typedef typename T3 arg3type;
	typedef typename T4 arg4type;

	LuaGenericFunction(std::tr1::shared_ptr<lua_State> state, int index) : LuaFunctionBase(state, index)
	{
	}

	typename rettype Invoke(arg1type arg1, arg2type arg2)
	{
		PushToStack();
		pusher<arg1type>::push(state, arg1);
		pusher<arg2type>::push(state, arg2);
		pusher<arg3type>::push(state, arg3);
		pusher<arg4type>::push(state, arg4);
		lua_call(state.get(), 4, 1);
		return popper<rettype>::pop(state);
	}
	
	static int staticFunction(lua_State* state)
	{
		std::tr1::function<R(T1,T2,T3,T4)>* func = (std::tr1::function<R(T1,T2,T3,T4)>*)lua_touserdata(state, lua_upvalueindex(1));
		arg4type arg4 = popper<arg4type>::pop(LuaNoDestructor(state));
		arg3type arg3 = popper<arg3type>::pop(LuaNoDestructor(state));
		arg2type arg2 = popper<arg2type>::pop(LuaNoDestructor(state));
		arg1type arg1 = popper<arg1type>::pop(LuaNoDestructor(state));
		R result = func->operator()(arg1, arg2, arg3, arg4);
		pusher<rettype>::push(LuaNoDestructor(state), result);
		return 1;
	}
};

template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5>
class LuaGenericFunction<R(T1,T2,T3,T4,T5)> : public LuaFunctionBase
{
public:
	typedef typename R rettype;
	typedef typename T1 arg1type;
	typedef typename T2 arg2type;
	typedef typename T3 arg3type;
	typedef typename T4 arg4type;
	typedef typename T5 arg5type;

	LuaGenericFunction(std::tr1::shared_ptr<lua_State> state, int index) : LuaFunctionBase(state, index)
	{
	}

	typename rettype Invoke(arg1type arg1, arg2type arg2)
	{
		PushToStack();
		pusher<arg1type>::push(state, arg1);
		pusher<arg2type>::push(state, arg2);
		pusher<arg3type>::push(state, arg3);
		pusher<arg4type>::push(state, arg4);
		pusher<arg5type>::push(state, arg5);
		lua_call(state.get(), 5, 1);
		return popper<rettype>::pop(state);
	}
	
	static int staticFunction(lua_State* state)
	{
		std::tr1::function<R(T1,T2,T3,T4,T5)>* func = (std::tr1::function<R(T1,T2,T3,T4,T5)>*)lua_touserdata(state, lua_upvalueindex(1));
		arg5type arg5 = popper<arg5type>::pop(LuaNoDestructor(state));
		arg4type arg4 = popper<arg4type>::pop(LuaNoDestructor(state));
		arg3type arg3 = popper<arg3type>::pop(LuaNoDestructor(state));
		arg2type arg2 = popper<arg2type>::pop(LuaNoDestructor(state));
		arg1type arg1 = popper<arg1type>::pop(LuaNoDestructor(state));
		R result = func->operator()(arg1, arg2, arg3, arg4, arg5);
		pusher<rettype>::push(LuaNoDestructor(state), result);
		return 1;
	}
};

template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class LuaGenericFunction<R(T1,T2,T3,T4,T5,T6)> : public LuaFunctionBase
{
public:
	typedef typename R rettype;
	typedef typename T1 arg1type;
	typedef typename T2 arg2type;
	typedef typename T3 arg3type;
	typedef typename T4 arg4type;
	typedef typename T5 arg5type;
	typedef typename T6 arg6type;

	LuaGenericFunction(std::tr1::shared_ptr<lua_State> state, int index) : LuaFunctionBase(state, index)
	{
	}

	typename rettype Invoke(arg1type arg1, arg2type arg2)
	{
		PushToStack();
		pusher<arg1type>::push(state, arg1);
		pusher<arg2type>::push(state, arg2);
		pusher<arg3type>::push(state, arg3);
		pusher<arg4type>::push(state, arg4);
		pusher<arg5type>::push(state, arg5);
		pusher<arg6type>::push(state, arg6);
		lua_call(state.get(), 6, 1);
		return popper<rettype>::pop(state);
	}
	
	static int staticFunction(lua_State* state)
	{
		std::tr1::function<R(T1,T2,T3,T4,T5,T6)>* func = (std::tr1::function<R(T1,T2,T3,T4,T5,T6)>*)lua_touserdata(state, lua_upvalueindex(1));
		arg6type arg6 = popper<arg6type>::pop(LuaNoDestructor(state));
		arg5type arg5 = popper<arg5type>::pop(LuaNoDestructor(state));
		arg4type arg4 = popper<arg4type>::pop(LuaNoDestructor(state));
		arg3type arg3 = popper<arg3type>::pop(LuaNoDestructor(state));
		arg2type arg2 = popper<arg2type>::pop(LuaNoDestructor(state));
		arg1type arg1 = popper<arg1type>::pop(LuaNoDestructor(state));
		R result = func->operator()(arg1, arg2, arg3, arg4, arg5, arg6);
		pusher<rettype>::push(LuaNoDestructor(state), result);
		return 1;
	}
};

template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
class LuaGenericFunction<R(T1,T2,T3,T4,T5,T6,T7)> : public LuaFunctionBase
{
public:
	typedef typename R rettype;
	typedef typename T1 arg1type;
	typedef typename T2 arg2type;
	typedef typename T3 arg3type;
	typedef typename T4 arg4type;
	typedef typename T5 arg5type;
	typedef typename T6 arg6type;
	typedef typename T7 arg7type;

	LuaGenericFunction(std::tr1::shared_ptr<lua_State> state, int index) : LuaFunctionBase(state, index)
	{
	}

	typename rettype Invoke(arg1type arg1, arg2type arg2)
	{
		PushToStack();
		pusher<arg1type>::push(state, arg1);
		pusher<arg2type>::push(state, arg2);
		pusher<arg3type>::push(state, arg3);
		pusher<arg4type>::push(state, arg4);
		pusher<arg5type>::push(state, arg5);
		pusher<arg6type>::push(state, arg6);
		pusher<arg7type>::push(state, arg7);
		lua_call(state.get(), 7, 1);
		return popper<rettype>::pop(state);
	}
	
	static int staticFunction(lua_State* state)
	{
		std::tr1::function<R(T1,T2,T3,T4,T5,T6,T7)>* func = (std::tr1::function<R(T1,T2,T3,T4,T5,T6,T7)>*)lua_touserdata(state, lua_upvalueindex(1));
		arg7type arg7 = popper<arg7type>::pop(LuaNoDestructor(state));
		arg6type arg6 = popper<arg6type>::pop(LuaNoDestructor(state));
		arg5type arg5 = popper<arg5type>::pop(LuaNoDestructor(state));
		arg4type arg4 = popper<arg4type>::pop(LuaNoDestructor(state));
		arg3type arg3 = popper<arg3type>::pop(LuaNoDestructor(state));
		arg2type arg2 = popper<arg2type>::pop(LuaNoDestructor(state));
		arg1type arg1 = popper<arg1type>::pop(LuaNoDestructor(state));
		R result = func->operator()(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
		pusher<rettype>::push(LuaNoDestructor(state), result);
		return 1;
	}
};

template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
class LuaGenericFunction<R(T1,T2,T3,T4,T5,T6,T7,T8)> : public LuaFunctionBase
{
public:
	typedef typename R rettype;
	typedef typename T1 arg1type;
	typedef typename T2 arg2type;
	typedef typename T3 arg3type;
	typedef typename T4 arg4type;
	typedef typename T5 arg5type;
	typedef typename T6 arg6type;
	typedef typename T7 arg7type;
	typedef typename T8 arg8type;

	LuaGenericFunction(std::tr1::shared_ptr<lua_State> state, int index) : LuaFunctionBase(state, index)
	{
	}

	typename rettype Invoke(arg1type arg1, arg2type arg2, arg3type arg3, arg4type arg4, arg5type arg5, arg6type arg6, arg7type arg7, arg8type arg8)
	{
		PushToStack();
		pusher<arg1type>::push(state, arg1);
		pusher<arg2type>::push(state, arg2);
		pusher<arg3type>::push(state, arg3);
		pusher<arg4type>::push(state, arg4);
		pusher<arg5type>::push(state, arg5);
		pusher<arg6type>::push(state, arg6);
		pusher<arg7type>::push(state, arg7);
		pusher<arg8type>::push(state, arg8);
		lua_call(state.get(), 8, 1);
		return popper<rettype>::pop(state);
	}
	
	static int staticFunction(lua_State* state)
	{
		std::tr1::function<R(T1,T2,T3,T4,T5,T6,T7,T8)>* func = (std::tr1::function<R(T1,T2,T3,T4,T5,T6,T7,T8)>*)lua_touserdata(state, lua_upvalueindex(1));
		arg8type arg8 = popper<arg8type>::pop(LuaNoDestructor(state));
		arg7type arg7 = popper<arg7type>::pop(LuaNoDestructor(state));
		arg6type arg6 = popper<arg6type>::pop(LuaNoDestructor(state));
		arg5type arg5 = popper<arg5type>::pop(LuaNoDestructor(state));
		arg4type arg4 = popper<arg4type>::pop(LuaNoDestructor(state));
		arg3type arg3 = popper<arg3type>::pop(LuaNoDestructor(state));
		arg2type arg2 = popper<arg2type>::pop(LuaNoDestructor(state));
		arg1type arg1 = popper<arg1type>::pop(LuaNoDestructor(state));
		R result = func->operator()(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
		pusher<rettype>::push(LuaNoDestructor(state), result);
		return 1;
	}
};

// I sincerely do not think one should have more than 3 parameters into a function without naming them with a table.
// I am just providing 8 because I'm nice.

#endif // LUAGENERALGENERICFUNCTION_H

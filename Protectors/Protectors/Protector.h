#pragma once
#include <vector>
#include <functional>

namespace Waw
{

	using Func_Bool_Vector = bool(*)(std::vector<double>*);

	template <typename Var_Type>
	class Protector
	{
	public:
		Protector(Var_Type value, Func_Bool_Vector getter, Func_Bool_Vector setter);
		Protector(Var_Type value);

		Var_Type& operator()(std::vector<double>* getter_Arg_Value = std::vector<double>(0));

		Var_Type& Get_Value(std::vector<double>* getter_Arg_Value = std::vector<double>(0));
		void Set_Value(Var_Type value, std::vector<double>* setter_Arg_Value = std::vector<double>(0));

		void Set_Setter_Condition(Func_Bool_Vector setter);
		void Set_Getter_Condition(Func_Bool_Vector getter);

	private:
		Var_Type Value_;
		Func_Bool_Vector Getter_Condition_;
		Func_Bool_Vector Setter_Condition_;
	};

	#define WPROT Protector
}
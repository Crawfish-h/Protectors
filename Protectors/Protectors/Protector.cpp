#pragma once
#include "Protector.h"

namespace Waw
{
	template <typename Var_Type>
	Protector<Var_Type>::Protector(Var_Type value, Func_Bool_Vector getter, Func_Bool_Vector setter)
	{
		Value_ = value;

		if (getter == nullptr)
		{
			Getter_Condition_ = [](std::vector<double>* var)
			{
				return true;
			};
		}else
		{
			Getter_Condition_ = getter;
		}

		if (setter == nullptr)
		{
			Setter_Condition_ = [](std::vector<double>* var)
			{
				return true;
			};
		}else
		{
			Setter_Condition_ = setter;
		}
	}

	template <typename Var_Type>
	Protector<Var_Type>::Protector(Var_Type value)
	{
		Value_ = value;

		Getter_Condition_ = [](std::vector<double>* var)
		{
			return true;
		};

		Setter_Condition_ = [](std::vector<double>* var)
		{
			return true;
		};
	}

	template<typename Var_Type>
	Var_Type& Protector<Var_Type>::operator()(std::vector<double>* getter_Arg_Value)
	{
		if (Getter_Condition_(getter_Arg_Value) == true)
		{
			return Value_;
		}else
		{
			Var_Type return_Val = Var_Type();
			return return_Val;
		}
	}

	template <typename Var_Type>
	Var_Type& Protector<Var_Type>::Get_Value(std::vector<double>* getter_Arg_Value)
	{
		if (Getter_Condition_(getter_Arg_Value) == true)
		{
			return Value_;
		}else
		{
			Var_Type return_Val;
			return return_Val;
		}
	}

	template <typename Var_Type>
	void Protector<Var_Type>::Set_Value(Var_Type value, std::vector<double>* setter_Arg_Value)
	{
		if (Setter_Condition_(setter_Arg_Value) == true)
		{
			Value_ = Var_Type;
		}
	}

	template <typename Var_Type>
	void Protector<Var_Type>::Set_Setter_Condition(Func_Bool_Vector setter)
	{
		Setter_Condition_ = setter;
	}

	template <typename Var_Type>
	void Protector<Var_Type>::Set_Getter_Condition(Func_Bool_Vector getter)
	{
		Getter_Condition_ = getter;
	}
}

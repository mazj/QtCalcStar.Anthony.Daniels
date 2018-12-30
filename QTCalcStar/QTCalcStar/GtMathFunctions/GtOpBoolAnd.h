/*
**	This file is part of the GtCalc Function Evaluator library.
**  License information is in the GtLicense.h file.
**	This software was developed by:
**	
**  Anthony Daniels (copyright 2014)
** AnthonyDaniels99@gmail.com
**
**  GtCalc is free software: you can redistribute it and/or modify
**  it under the terms of the GNU Lesser General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**
**  GtCalc is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU Lesser General Public License for more details.
**
**  You should have received a copy of the GNU Lesser General Public License
**  along with GtCalc.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#ifndef GtCalc_OP_BoolAnd_H
#define GtCalc_OP_BoolAnd_H

#include "..\GtOpBase.h"
#include "..\GtOpBaseFactory.h"
namespace GT
{
	namespace GtCalc
	{

		class GtOpBoolAnd : public GtOpBase
		{
		public:
			//!Default Constructor
			GtOpBoolAnd();
			//!Default Destructor
			~GtOpBoolAnd();

			//!Perform the operation on the stack
			virtual int OpEval(std::vector<GtRpnUnit> & arrObjCalcStack, bool & blnCalcSuccessful, int intCurrPos);

		};

		//OBJECT FACTORY REGISTRATION CODE
		static bool blnGtOpBoolAnd_Registered = GtCalc::GetOpBaseFactoryPtr()->Register<GtOpBoolAnd>("&&");
		static bool blnGtOpBoolAnd2_Registered = GtCalc::GetOpBaseFactoryPtr()->Register<GtOpBoolAnd>("AND");
		static bool blnGtOpBoolAnd3_Registered = GtCalc::GetOpBaseFactoryPtr()->Register<GtOpBoolAnd>("GtOpBoolAnd");
	}//end namespace
}//end namespace gt
#endif
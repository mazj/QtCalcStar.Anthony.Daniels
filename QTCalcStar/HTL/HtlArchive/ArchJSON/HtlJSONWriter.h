/*
**	This file is part of the XMLStar.
**	This software was developed by:
**	
**  Anthony Daniels, Mi Yan
**	The University of Michigan
**	Department of Naval Architecture & Marine Engineering
**	Department of Computer Science
**
**  XMLStar is free software: you can redistribute it and/or modify
**  it under the terms of the GNU Lesser General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  The United States of America Department of Defense has unlimited 
**	usage, redistribution, and modification rights to XMLStar.
**
**  XMLStar is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU Lesser General Public License for more details.
**
**  You should have received a copy of the GNU Lesser General Public License
**  along with XMLStar.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#ifndef HTL_JSON_WRITER_H
#define HTL_JSON_WRITER_H
#include "..\..\modHtlGlobal.h"
#include "..\HtlElement.h"

using namespace std;

namespace HTL{


	class HTL_DLLAPI HtlJSONWriter
	{
	public:

		//PUBLIC CONSTRUCTORS & DESTRUCTOR/////////////////////////////
      HtlJSONWriter(void);
		virtual ~HtlJSONWriter(void);
		//PUBLIC OPERATOR OVERLOADS
		//!Set pointer to the element
		void Set_ptrElement(HtlElement * ptrElement);
		//!Get the pointer to the element
		HtlElement * Get_ptrElement(void);	
		//!Sets the number of indent spaces per level
		void Set_intNumIndentSpaces(unsigned int intNumSpacesIndent);

		//XML SERIALIZATION AND DE-SERIALIZATION METHODS///////////

		//!Save the entire XML Tree to desired string output
		virtual int SaveJSONTree(HtlElement * ptrCurrTop, std::string & strOutput, bool blnWithFormatting);
		virtual int SaveJSONTree(HtlElement * ptrCurrTop, std::ostream & strStreamOut, bool blnWithFormatting);
		virtual int SaveJSONTree(HtlElement * ptrCurrTop, std::ofstream & strStreamOut, bool blnWithFormatting);
		//!Update the indexes
		int UpdateIndexes(HtlElement * ptrCurrTop);

		//!Gets the number of indent spaces per level
		unsigned int Get_intNumIndentSpaces(void);
		//!Save the XML Element based with or without formatting
		int SaveJSONElement(HtlElement * ptrElement, std::string & strOutput,int elemIndex, int elemTotal, bool blnWithFormatting);

	protected:
		void WriteIndent(std::string & strOutput, unsigned int intLevel);
		//!write the open tag including all attributes
		int WriteOpenTag(HtlElement * ptrElement, std::string & strOutput, bool blnWithFormatting);
      //!write the value for the element
      int WriteValueInline(HtlElement * ptrElement, std::string & strOutput, bool blnWithFormatting);
		//!write the value for the element
		int WriteValue(HtlElement * ptrElement, std::string & strOutput, bool blnWithFormatting);
      //!write the node close tag
      int WriteSeperator(HtlElement * ptrElement, std::string & strOutput, bool blnWithFormatting);
		//!checks to see if the string is all whitespace
		bool IsAllWhiteSpace(const std::string & strInput); 

	private:
		//pointer to the 
		HtlElement * m_ptrElement;
		std::string m_str;
		unsigned int m_intNumIndentSpaces;

	};//end XDLWriter class definition

};//end namespace XMLStar
#endif
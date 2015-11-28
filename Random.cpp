/*****************************************************************************
/**
  @file				Random.cpp
  @author			Alessio Leoncini
	@brief			Code file with definitions for Random, a class for the
							generation of random numbers
*/
/****************************************************************************/

#include "Random.h"

/************************** CONSTRUCTORS/DESTRUCTOR *************************/
//////////////////////////////////////////////////////////////////////////////
/// \par PROCEDURE:
Random::Random()
{
	/// Initialization
	Init();
}

//////////////////////////////////////////////////////////////////////////////
/// \par PROCEDURE:
Random::~Random()
{
	Reset();
}

/********************************* OPERATORS ********************************/
//////////////////////////////////////////////////////////////////////////////
/// \par PROCEDURE:
ostream & operator << ( ostream & o, Random & X)
{
	o<<"**** Random class dump ****"<<endl;
	o<<"  _seed = "<<X._seed<<endl;
	return o;
}

/****************************** BASIC HANDLING ******************************/
//////////////////////////////////////////////////////////////////////////////
/// \par PROCEDURE:
void Random::Init()
{
	/// Reset
	Reset();
}

//////////////////////////////////////////////////////////////////////////////
/// \par PROCEDURE:
void Random::Reset()
{
	/// Seed set to 1
	_seed = 1;
	/// Starting values for other members
	aa = 16807L;
	mm = 2147483647L;
	qq = 127773L;
	rr = 2836L;
}

//////////////////////////////////////////////////////////////////////////////
/// \par PROCEDURE:
void Random::Dump()
{
	cout<<*this;
}

/***************************** ACCESS METHODS *******************************/
//////////////////////////////////////////////////////////////////////////////
/// \par PROCEDURE:
void Random::Set_Seed(long seed)
{
	if(seed == 0)
	{
		cout<<"Error: trying to set a null seed"<<endl;
		return;
	}
	_seed = seed;
}

//////////////////////////////////////////////////////////////////////////////
/// \par PROCEDURE:
long Random::Get_Seed()
{
	return _seed;
}

//////////////////////////////////////////////////////////////////////////////
/// \par PROCEDURE:
double Random::Get_Random()
{
	hh = _seed/qq;
	lo = _seed-hh*qq;
	test = aa*lo-rr*hh;
	if (test > 0)
  {
		_seed = test;
  }
	else
  {
		_seed = test+mm;
  }
	number = (double)_seed/(double)mm;
	return number;
}

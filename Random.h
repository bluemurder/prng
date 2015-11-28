/*****************************************************************************
/**
  @file				Random.h
  @author			Alessio Leoncini
	@brief			Header file with definitions for Random, a class for the
							generation of random numbers
*/
/****************************************************************************/

#ifndef Random_h
#define Random_h

#include <iostream>

using namespace std;

/**
@class Random
@brief Random Number Generator. It generates [0,1) random number
*/
class Random
{

/////////////////////////////// PRIVATE Segment //////////////////////////////
private:
/////////////////////////////// PROTECTED Segment ////////////////////////////
protected:
	long _seed;
	double number;
	long   aa;
	long   mm;
	long   qq;
	long   rr;
	long   lo;
	long   hh;
	long   test;

/////////////////////////////// PUBLIC Segment ///////////////////////////////
public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{

	/// Default constructor
	Random();
	/// Destructor
	virtual ~Random();
	//@}

	/// @name OPERATORS
	/// @{

	/// Print operator
	friend ostream & operator << ( ostream & o, Random & X); 
	//@}

	/// @name BASIC HANDLING
	/// @{

	/// Default initialization
	void Init();
	/// Object erasure
	void Reset();
	/// Object printout for diagnostic
	void Dump();
	//@}

	/// @name ACCESS METHODS
	/// @{

	/// Set the seed paramenter
	void Set_Seed(long seed);
	/// Get the seed parameter
	long Get_Seed();
	/// Get a random number [0,1)
	double Get_Random();
	//@}
};

#endif

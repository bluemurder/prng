/*****************************************************************************
/**
  @file       Random.hpp
  @author     Alessio Leoncini
  @brief      Header file with definitions for Random, a class for the
              generation of random numbers
*/
/****************************************************************************/

#pragma once

/**
@class Random
@brief Random Number Generator. It generates [0,1) random numbers
*/
class Random
{
	
protected:

  long m_seed;
  double m_number;
  long m_aa;
  long m_mm;
  long m_qq;
  long m_rr;
  long m_lo;
  long m_hh;
  long m_test;

public:

  /// Default constructor
  Random();
  
  /// Destructor
  virtual ~Random();

  /// Default initialization
  void Init();
  
  /// Object erasure
  void Reset();

  /// Set the seed paramenter
  void SetSeed(long seed);
  
  /// Get the seed parameter
  long GetSeed();
  
  /// Get a random number [0,1)
  double GetRandom();
};

#endif

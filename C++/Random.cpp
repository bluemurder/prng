/*****************************************************************************
/**
  @file       Random.cpp
  @author     Alessio Leoncini
  @brief      Code file with definitions for Random, a class for the
              generation of random numbers
*/
/****************************************************************************/

#include "Random.h"

Random::Random()
{
  Init();
}

Random::~Random()
{
  Reset();
}

void Random::Init()
{
  Reset();
}

void Random::Reset()
{
  // Seed set to 1
  m_seed = 1;
  // Starting values for other members
  m_aa = 16807L;
  m_mm = 2147483647L;
  m_qq = 127773L;
  m_rr = 2836L;
}

/***************************** ACCESS METHODS *******************************/
//////////////////////////////////////////////////////////////////////////////
/// \par PROCEDURE:
void Random::Set_Seed(long seed)
{
  if(seed == 0)
  {
    // Error: null seed
    return;
  }
  m_seed = seed;
}

//////////////////////////////////////////////////////////////////////////////
/// \par PROCEDURE:
long Random::Get_Seed()
{
  return m_seed;
}

//////////////////////////////////////////////////////////////////////////////
/// \par PROCEDURE:
double Random::Get_Random()
{
  m_hh = m_seed / m_qq;
  m_lo = m_seed - m_hh * m_qq;
  m_test = m_aa * m_lo - m_rr * m_hh;
  if (m_test > 0)
  {
    m_seed = m_test;
  }
  else
  {
    m_seed = m_test + m_mm;
  }
  m_number = (double)m_seed / (double)m_mm;
  return m_number;
}

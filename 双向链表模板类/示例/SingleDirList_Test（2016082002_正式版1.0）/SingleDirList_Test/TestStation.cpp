#include "stdafx.h"
#include "TestStation.h"


CTestStation::CTestStation()
	:m_nStationNumber(0)
	, m_nCardNumber(0)
{
}


CTestStation::~CTestStation()
{
}

int CTestStation::getStationNumber()
{
	return m_nStationNumber;
}

void CTestStation::setStationNumber(int nIndoex)
{
	m_nStationNumber = nIndoex;
}

int CTestStation::getCardNumber()
{
	return m_nCardNumber;
}

void CTestStation::setCardNumber(int nIndoex)
{
	m_nCardNumber = nIndoex;
}

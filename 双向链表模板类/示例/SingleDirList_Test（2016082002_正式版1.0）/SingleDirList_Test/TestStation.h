#pragma once
class CTestStation
{
public:
	CTestStation();
	~CTestStation();

	int getStationNumber();
	void setStationNumber(int nIndoex);
	int getCardNumber();
	void setCardNumber(int nIndoex);

	int m_nStationNumber;
	int m_nCardNumber;
};


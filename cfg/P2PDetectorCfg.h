#ifndef P2PDETECTORCFG_H_
#define P2PDETECTORCFG_H_

#include <cfg/XMLElement.h>
#include <cfg/Cfg.h>

#include "concentrator/P2PDetector.h"

#include <string>

using namespace std;


class P2PDetectorCfg
	: public CfgHelper<P2PDetector, P2PDetectorCfg>
{
public:
	friend class ConfigManager;
	
	virtual P2PDetectorCfg* create(XMLElement* e);
	virtual ~P2PDetectorCfg();
	
	virtual P2PDetector* createInstance();
	virtual bool deriveFrom(P2PDetectorCfg* old);
	
protected:
	
	uint32_t intLength;	/** length of interval in seconds when to check for p2p hosts*/
	uint32_t subnet; // subnet to research
	uint32_t subnetmask; // corresponding subnetmask
	string analyzerid;
	string idmefTemplate;
	
	//criterias
	double udpRateThreshold;
	double udpHostRateThreshold;
	double tcpRateThreshold;
	double coexistentTCPConsThreshold;
	double rateLongTCPConsThreshold;
	double tcpVarianceThreshold;
	double failedConsPercentThreshold;
	double tcpFailedRateThreshold;
	double tcpFailedVarianceThreshold;
	
	P2PDetectorCfg(XMLElement*);

	bool setSubnet(string& str);
};


#endif /*P2PDETECTORCFG_H_*/
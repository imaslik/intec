#include "CIntecIPDevice.h"
class CIntecIPDeviceH: public CIntecIPDevice
{

public : 

	CIntecIPDeviceH(IntecUsbDeviceType devType, DWORD devIndex,IntecDeviceOperationMode mode,IntecDeviceDriverType driverType);
	virtual const int SetDeviceMode(IntecDeviceOperationMode mode);
	virtual const int GetDeviceName(UCHAR *szBuffer);
	virtual const int GetDeviceVersion(UCHAR *szBuffer);
	virtual const int GetNumOfSubDevices(UINT *subDevicesMask);
	virtual const int GetSubDeviceName(UINT subDeviceIndex, UCHAR *szBuffer);
	virtual const int GetSubDeviceVersion(UINT subDeviceIndex, UCHAR *szBuffer);
	virtual const IntecDeviceOperationMode GetSubDeviceMode(UINT subDeviceIndex);
	virtual const int StartSubDeviceBootMode(UINT  subDeviceIndex);
	virtual const int StopSubDeviceBootMode(UINT  subDeviceIndex);
	virtual const int SetDeviceSiteNumber(UINT siteNum);
	virtual const int GetDeviceSiteNumber(UINT &siteNum);
	virtual ~CIntecIPDeviceH();

protected:

private:

};

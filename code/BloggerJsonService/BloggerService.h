/****************************** Module Header ******************************\
* Module Name:  BloggerService.h
* Project:      BloggerJsonServer
\***************************************************************************/

#pragma once

#include "ServiceBase.h"


class BloggerService : public CServiceBase
{
public:

    BloggerService(PWSTR pszServiceName, 
        BOOL fCanStop = TRUE, 
        BOOL fCanShutdown = TRUE, 
        BOOL fCanPauseContinue = FALSE);
    virtual ~BloggerService(void);

protected:

    virtual void OnStart(DWORD dwArgc, PWSTR *pszArgv);
    virtual void OnStop();

    void ServiceWorkerThread(void);

private:

    BOOL m_fStopping;
    HANDLE m_hStoppedEvent;
};
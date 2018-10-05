/////////////////////////////////////////////////////////////////////////////////////////////
// Timer.cpp
//
// Time Measure Stop Watch Classes
/////////////////////////////////////////////////////////////////////////////////////////////

#include "Timer.h"

#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////////////////////
//Get time function
inline MILLISEC_TIME GetStopWatchTime()
{
#ifdef WINTIME_MEASURE
    return timeGetTime();
#else
    return clock();
#endif //time measure variables
}

/////////////////////////////////////////////////////////////////////////////////////////////
//Time value convertion function
inline float ConvertMilliSecsToFloat(MILLISEC_TIME time_val)
{
#ifdef WINTIME_MEASURE
    return float(time_val) / 1000.0f;
#else
    return (float) time_val/CLOCKS_PER_SEC;
#endif //time measure variables
}
/////////////////////////////////////////////////////////////////////////////////////////////
inline unsigned int ConvertMilliSecsToUInt(MILLISEC_TIME time_val)
{
#ifdef WINTIME_MEASURE
    return (unsigned int) time_val;
#else
    return (unsigned int) time_val;
#endif //time measure variables
}

/////////////////////////////////////////////////////////////////////////////////////////////
CStopWatch::CStopWatch():mStartTime(0),mCurrTime(0),mActive(false),mPaused(false)
{
}
/////////////////////////////////////////////////////////////////////////////////////////////
CStopWatch::~CStopWatch()
{
}
/////////////////////////////////////////////////////////////////////////////////////////////   
void CStopWatch::Start()
{
    if(IsActive() || IsPaused()) return ;
    
    mStartTime = GetStopWatchTime();
    mCurrTime = mStartTime;
    mActive = true;
    mPaused = false;
}
/////////////////////////////////////////////////////////////////////////////////////////////
void CStopWatch::Pause()
{
    if(!IsActive()) return ;
    if(IsPaused()) return ;
    mCurrTime = GetStopWatchTime();
    mPaused = true;
}
/////////////////////////////////////////////////////////////////////////////////////////////
void CStopWatch::Resume()
{
    if(!IsActive()) return ;
    if(!IsPaused()) return ;
    mPaused = false;
}
/////////////////////////////////////////////////////////////////////////////////////////////
void CStopWatch::Reset()
{
    mActive = false;
    mPaused = false;
    mStartTime = 0; 
    mCurrTime = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
bool CStopWatch::IsActive() const
{ 
    return mActive;
}
/////////////////////////////////////////////////////////////////////////////////////////////
bool CStopWatch::IsPaused() const
{
    return mPaused;
}

/////////////////////////////////////////////////////////////////////////////////////////////
float CStopWatch::GetTime()
{
    fprintf(stderr, "GetTime: mStartTime = %d, mCurrTime = %d\n",mStartTime,mCurrTime);
    if(!IsActive()) return 0.0f;
    if(IsPaused()) return ConvertMilliSecsToFloat(mCurrTime - mStartTime);
    
    return ConvertMilliSecsToFloat(GetStopWatchTime() - mStartTime);
}
/////////////////////////////////////////////////////////////////////////////////////////////
unsigned int CStopWatch::GetTicks()
{
    fprintf(stderr, "GetTicks: mStartTime = %d, mCurrTime = %d\n",mStartTime,mCurrTime);
    if(!IsActive()) return 0;
    if(IsPaused()) return ConvertMilliSecsToUInt(mCurrTime - mStartTime);
    
    return ConvertMilliSecsToUInt(GetStopWatchTime() - mStartTime);
}
/////////////////////////////////////////////////////////////////////////////////////////////

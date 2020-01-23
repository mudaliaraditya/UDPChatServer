#include "Logger.h"

using namespace std;

long getMicrotime()
{
   struct timeval currentTime;
   gettimeofday(&currentTime, NULL);
   //return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
   return currentTime.tv_usec;
}


int InitiateLoggingFor(fstream& cFileStream,char* cPath,char* cName,char* cExt)
{
   //LOG File Handling START
   time_t lnTime;
   struct tm*  lpsttm = NULL; 
   char lcErrorLogFileName[200] = {0};
   lnTime = time(NULL);
   lpsttm  = gmtime(&lnTime);
   //snprintf(lcBuffera,200,"%d:%d:%d%d-%d-%d",psttm->tm_hour,psttm->tm_min,psttm->tm_sec,psttm->tm_mday,psttm->tm_mon,psttm->tm_year );
   snprintf(lcErrorLogFileName,200,"%s/%s-%02d-%02d-%04d_%02d%02d%02d.%s",cPath,cName,lpsttm->tm_mday,lpsttm->tm_mon +1  ,lpsttm->tm_year + 1900,lpsttm->tm_hour,lpsttm->tm_min,lpsttm->tm_sec,cExt);
   TESTLOG( "%s %s"," log file name ", lcErrorLogFileName );
    cFileStream.open(lcErrorLogFileName,ios::in|ios::out | ios::app);
   if( cFileStream.fail())
   {
      LOG_LOGGER("%s"," failed truncating or creating new file"); 
      LOG_LOGGER( "%s"," failed truncating or creating new file");
      g_cfstream.open(lcErrorLogFileName,ios::in|ios::out|ios::trunc);
      if( cFileStream.fail())
      {
          return EXIT_FAILURE;
      }
       cFileStream.clear();
   }
    cFileStream.seekp(ios::end); //output
    cFileStream.seekg(ios::end);
   return 0;
}

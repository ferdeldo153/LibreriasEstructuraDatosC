#ifndef KBCAFE_THREAD_H
#define KBCAFE_THREAD_H
#ifdef _WIN32
#ifndef _WINDOWS_
#include <windows.h>
#endif
#else
#error _WIN32 must be defined before you include thread.h
#endif
namespace kbcafe{
          class thread{
                #ifdef _WIN32
                static DWORD WINAPI ThreadFunc(LPVOID pv){
                       try{
                           (reinterpret_cast<thread *>(pv))->run();
                       }catch(...){}
                       return 0;
                }
                #elif defined(__sun)
                #else
                #endif
                public:
                #ifdef _WIN32
                typedef DWORD threadid;
                #elif defined(__sun)
                #else
                #endif
                // Some values
                int value1 ;
                
                // Constructor
                thread(){}
                virtual ~thread(){}
                
                // Methods
                static threadid getthreadid(){
                       #ifdef _WIN32
                       return ::GetCurrentThreadId();
                       #elif defined(__sun)
                       #else
                       #endif
                }
                static void sleep(long milliseconds=1){
                       #ifdef _WIN32
                       ::Sleep(milliseconds);
                       #elif defined(__sun)
                       #else
                       #endif
                }
                threadid start(){
                         threadid id;
                         #ifdef _WIN32
                         ::CreateThread(NULL, 0, ThreadFunc, this, 0, &id);
                         #elif defined(__sun)
                         #else
                         #endif
                         return id;
                }
                virtual void run()=0;
                
                // Getters and Setters
                public: void setvalue1(int in){
                    value1 = in ;
                }
                public: int getvalue1(){
                    return value1;
                }                
          };
};
#endif       
/*          
class MyThread : public kbcafe::thread{
      public: virtual void run(){
              while(true){
                
                 // Poceso del hilo
              }
      };
};*/
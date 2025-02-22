
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;



mutex Lock;


void Trade(std::string TraderName) {
    unique_lock<mutex> TradeLock(Lock);
    std::cout << TraderName << " is setting up the systematic trading applications\n";
    
    std::cout << TraderName << " is done setting up the algorithms. \n";
    TradeLock.unlock();
    // the TradeLock auto unlocks when Lock goes out of scope
   
}





int main()
{
   
    thread t1(Trade, "Jad the quant trader");
    thread t2(Trade, "Shan the quant trader");

    t1.join();
    t2.join();

};



#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
// #include "spinlock.h"

class Spinlock {
    std::atomic<bool> locked = 0;
public:
    void lock() {
        while(locked.exchange(true)) {
            sched_yield();
        }
    }

    void unlock() {
        locked.store(false);
    }
};


int shared_variable = 0;
const int iter_num = 10000000;


void increment(Spinlock& mutex) {
	mutex.lock();
	for (int i = 0; i < iter_num; ++i) {
        ++shared_variable;
    }
	mutex.unlock();
}

void decrement(Spinlock& mutex) {
    for (int i = 0; i < iter_num; ++i) {
        /// actions
        {
            std::lock_guard lock{mutex};
            // 
            --shared_variable;
        }
        // actions
    }
}

int main() {

	Spinlock mutex;
	
	std::thread thread1([&mutex]() { increment(mutex);});
    std::thread thread2([&mutex]() { decrement(mutex);});

    thread1.join();
    thread2.join();

    std::cout << "Final value of shared_variable: " << shared_variable << std::endl;
    return 0;
}


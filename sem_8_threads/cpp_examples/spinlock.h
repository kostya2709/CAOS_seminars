#include <atomic>

class Spinlock {

	std::atomic<bool> locked;

public:
	
	void lock() {
		while (locked.exchange(true)) {
			
		}
	}

	void unlock() {
		locked.store(false);
	}

};



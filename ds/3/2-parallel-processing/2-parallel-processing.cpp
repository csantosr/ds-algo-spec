#include <iostream>
#include <vector>

using namespace std;

struct taskCompleted {
	int id;
	long long start;
};

struct Worker {
	int id;
	long long nextAvailable;
};

void swapElements(Worker* a, Worker* b) {
	Worker temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(vector<Worker*> arr, int size, int i) {
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	if (left<size) {
		if (arr[left]->nextAvailable < arr[largest]->nextAvailable) {
			largest = left;
		} else if (arr[left]->nextAvailable == arr[largest]->nextAvailable && arr[left]->id < arr[largest]->id) {
			largest = left;
		}
	}
	if (right<size) {
		if (arr[right]->nextAvailable < arr[largest]->nextAvailable) {
			largest = right;
		} else if (arr[right]->nextAvailable == arr[largest]->nextAvailable && arr[right]->id < arr[largest]->id) {
			largest = right;
		}
	}
	if (largest != i) {
		swapElements(arr[i], arr[largest]);
		heapify(arr, size, largest);
	}
}

int main() {
	int threadsCount, tasksCount;
	cin >> threadsCount >> tasksCount;
	vector<Worker*> threads(threadsCount);
	vector<taskCompleted*> tasksToPrint;
	for (int i=0; i<threadsCount; ++i) {
		threads[i] = new Worker();
		threads[i]->id = i;
		threads[i]->nextAvailable = 0;
	}
	vector<long long> times;
	for (int i=0; i<tasksCount; ++i) {
		long long time;
		cin >> time;
		times.push_back(time);
	}
	if (tasksCount <= threadsCount) {
		for (int i=0; i < tasksCount; ++i) {
			cout << i << ' ' << 0 << endl;
		}
		return 0;
	}
	for (int i=0; i<tasksCount; ++i) {
		long long time = times[i];
		taskCompleted *t = new taskCompleted();
		t->id = threads[0]->id;
		t->start = threads[0]->nextAvailable;
		tasksToPrint.push_back(t);
		threads[0]->nextAvailable += time;
		swapElements(threads[0], threads[threadsCount -1]);
		heapify(threads, threadsCount, 0);
	}
	for (auto tc : tasksToPrint) {
		cout << tc->id << ' ' << tc->start << endl;
	}
	return 0;
}

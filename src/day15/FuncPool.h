#pragma once
#include<queue>
#include<functional>
#include<mutex>
#include<condition_variable>
#include<atomic>
#include<cassert>

class FuncPool
{
private:
	std::queue<std::function<void(int)>> m_function_queue;
	std::queue<int> m_arg_queue;
	std::mutex m_lock;
	std::condition_variable m_data_condition;
	std::atomic<bool> m_accept_functions;

public:
	FuncPool();
	~FuncPool();
	void push(std::function<void(int)> func, int x);
	void done();
	void loopFunc();
};

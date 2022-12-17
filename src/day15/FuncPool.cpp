#include "FuncPool.h"

FuncPool::FuncPool() : m_function_queue(), m_lock(), m_data_condition(), m_accept_functions(true)
{
}

FuncPool::~FuncPool()
{
}

void FuncPool::push(std::function<void(int)> func, int x)
{
	std::unique_lock<std::mutex> lock(m_lock);
	m_function_queue.push(func);
	m_arg_queue.push(x);
	lock.unlock();
	m_data_condition.notify_one();
}

void FuncPool::done()
{
	std::unique_lock<std::mutex> lock(m_lock);
	m_accept_functions = false;
	lock.unlock();
	m_data_condition.notify_all();
}

void FuncPool::loopFunc()
{
	int arg;
	std::function<void(int)> func;
	while(true)
	{
		{
			std::unique_lock<std::mutex> lock(m_lock);
			m_data_condition.wait(lock, [this]() {return !m_function_queue.empty() || !m_accept_functions; });
			if(!m_accept_functions && m_function_queue.empty())
			{
				return;
			}
			func = m_function_queue.front();
			m_function_queue.pop();
			arg = m_arg_queue.front();
			m_arg_queue.pop();
		}
		func(arg);
	}
}
